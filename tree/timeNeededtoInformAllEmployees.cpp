/*
https://leetcode.com/problems/time-needed-to-inform-all-employees/
*/

// Solution 1: DFS
// Time complexity: O(n), Space complexity: O(1)
class Solution {
public:
    int dfs(int src, vector<int>& manager, vector<int>& informTime) {
        if (manager[src]!=-1) {
            informTime[src] += dfs(manager[src], manager, informTime);
            manager[src] = -1;
        }
        return informTime[src];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans=0;
        for (int i=0;i<n;i++) {
            ans = max(ans, dfs(i, manager, informTime));
        }
        return ans;
    }
};


// Solution 2: BFS
// Time complexity: O(n), Space complexity: O(n)
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        int i,j,src,srcT;
        for (i=0;i<n;i++) {
            if (manager[i]==-1) {
                src = i;
                continue;
            }
            adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        int ans = 0;
        q.push({src,informTime[src]});
        while (!q.empty()) {
            src = q.front().first;
            srcT = q.front().second;
            q.pop();
            for (auto u:adj[src]) {
                q.push({u, srcT+informTime[u]});
                ans = max(ans, srcT);
            }
        }
        return ans;
    }
};