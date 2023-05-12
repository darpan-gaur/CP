/*
https://leetcode.com/problems/uncrossed-lines/
*/

// Solution 1: - Recursive DP solution
// Time Complexity = O(n1*n2), Space Complexity = O(n1*n2)
class Solution {
public:
    vector<vector<int>> v;
    int solve(vector<int> nums1, vector<int> nums2,int i,int j){
        if (i<=0 || j<=0) return 0;
        if (v[i][j]!=-1) return v[i][j];
        if (nums1[i-1]==nums2[j-1]) v[i][j] = 1 + solve(nums1,nums2,i-1,j-1);
        else v[i][j] = max(solve(nums1,nums2,i-1,j),solve(nums1,nums2,i,j-1));
        return v[i][j];
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        v = vector<vector<int>> (n1+1, vector<int> (n2+1,-1));
        return solve(nums1,nums2,n1,n2);
    }
};

// Solution 2: - Iterative DP solution
// Time Complexity = O(n1*n2), Space Complexity = O(n1*n2)
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int i,j,n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> v(n1+1, vector<int> (n2+1,0));
        for (i=1;i<=n1;i++) {
            for (j=1;j<=n2;j++) {
                if (nums1[i-1] == nums2[j-1]) v[i][j] = 1 + v[i-1][j-1];
                else v[i][j] = max(v[i][j-1],v[i-1][j]);
            }
        }
        return v[n1][n2];
    }
};

// Solution 3: - Iterative DP with space optimization
// Time Complexity = O(n1*n2), Space Complexity = O(n2)
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int i,j,n1 = nums1.size(), n2 = nums2.size();
        vector<int> v1(n2+1,0), v2(n2+1,0);
        for (i=1;i<=n1;i++) {
            for (j=1;j<=n2;j++) {
                if (nums1[i-1] == nums2[j-1]) v2[j] = 1 + v1[j-1];
                else v2[j] = max(v2[j-1],v1[j]);
            }
            v1 = v2;
        }
        return v1[n2];
    }
};