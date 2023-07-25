/*
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
*/

// Solution 1, Time :- O(n*m), Space :- O(n*m)
class Solution {
public:
    bool chk(int i, int j, int m, int n) {
        if (min(i,j)<0 || i>=m || j>=n) return false;
        return true;
    }
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (dp[i][j]!=-1) return dp[i][j];
        int m = grid.size(), n= grid[0].size();
        int res = 0,k;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,-1,1};
        for (k=0;k<4;k++) {
            if (chk(i+dx[k], j+dy[k], m, n)) {
                if (grid[i+dx[k]][j+dy[k]] > grid[i][j]) {
                    res = max(res, dfs(i+dx[k], j+dy[k], grid, dp));
                }
            }
        }
        dp[i][j] = 1+res;
        return res+1;
    }
    int longestIncreasingPath(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        int res=0,i,j;
        for (i=0;i<m;i++) {
            for (j=0;j<n;j++) {
                res = max(res, dfs(i, j, grid, dp));
            }
        }
        return res;
    }
};