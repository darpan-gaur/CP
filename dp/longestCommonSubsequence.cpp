/*
https://leetcode.com/problems/longest-common-subsequence/


*/

// Solution 1: O(n1*n2) time, O(n2) space
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size(), i, j;
        vector<int> v1(n2+1,0), v2(n2+1,0);
        for (i=1;i<=n1;i++) {
            for (j=1;j<=n2;j++) {
                v2[j] = max(max(v1[j], v2[j-1]), v1[j-1] + (text1[i-1] == text2[j-1]));
            }
            v1 = v2;
        }
        return v1[n2];
    }
};