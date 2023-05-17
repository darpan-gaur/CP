/*
https://leetcode.com/problems/edit-distance/
*/

// Method 1 Recursive
// Time: O(3^m) Space: O(m) where m is the length of the bigger string
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        return minDistanceRecur(word1, word2, word1.size(), word2.size());
    }

    int minDistanceRecur(string word1, string word2, int word1Index, int word2Index)
    {
        if (word1Index == 0) return word2Index;
        if (word2Index == 0) return word1Index;

        if (word1[word1Index - 1] == word2[word2Index - 1])
        {
            return minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
        }
        else
        {
            int insertOperation = minDistanceRecur(word1, word2, word1Index, word2Index - 1);
            int deleteOperation = minDistanceRecur(word1, word2, word1Index - 1, word2Index);
            int replaceOperation = minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
            return min(insertOperation, min(deleteOperation, replaceOperation)) + 1;
        }
    }
};

// Method 2 Memoization
// Time: O(m*n) Space: O(m*n) where m and n are the lengths of the two strings
class Solution
{
public:
    vector<vector<int>> memo;
    int minDistance(string word1, string word2)
    {
        memo.resize(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return minDistanceRecur(word1, word2, word1.size(), word2.size());
    }

    int minDistanceRecur(string &word1, string &word2, int word1Index, int word2Index)
    {
        if (word1Index == 0)
        {
            return word2Index;
        }
        if (word2Index == 0)
        {
            return word1Index;
        }
        if (memo[word1Index][word2Index] != -1)
        {
            return memo[word1Index][word2Index];
        }
        int minEditDistance = 0;
        if (word1[word1Index - 1] == word2[word2Index - 1])
        {
            minEditDistance = minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
        }
        else
        {
            int insertOperation = minDistanceRecur(word1, word2, word1Index, word2Index - 1);
            int deleteOperation = minDistanceRecur(word1, word2, word1Index - 1, word2Index);
            int replaceOperation = minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
            minEditDistance = min(insertOperation, min(deleteOperation, replaceOperation)) + 1;
        }
        memo[word1Index][word2Index] = minEditDistance;
        return minEditDistance;
    }
};

// Method 3 DP Tabulation (Bottom Up)
// Time: O(m*n) Space: O(m*n) where m and n are the lengths of the two strings
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size(), i, j;
        vector<vector<int>> v(n1+1, vector<int> (n2+1,0));
        for (i=1;i<=n2;i++) v[0][i] = i;
        for (i=1;i<=n1;i++) v[i][0] = i;
        for (i=1;i<=n1;i++) {
            for (j=1;j<=n2;j++) {
                v[i][j] = min(min(v[i][j-1]+1, v[i-1][j]+1), v[i-1][j-1] + (word1[i-1]!=word2[j-1]));
            }
        }
        return v[n1][n2];
    }
};

// Method 4 DP Tabulation (Bottom Up) Space Optimized
// Time: O(m*n) Space: O(n) where m and n are the lengths of the two strings 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size(), i, j;
        vector<int> v_old(n2+1,0); vector<int> v_new(n2+1,0);
        for (i=1;i<=n2;i++) v_old[i] = i;
        for (i=1;i<=n1;i++) {
            v_new[0] = i;
            for (j=1;j<=n2;j++) {
                v_new[j] = min(min(v_new[j-1]+1, v_old[j]+1), v_old[j-1] + (word1[i-1]!=word2[j-1]));
            }
            v_old = v_new;
        }
        return v_old[n2];
    }
};
