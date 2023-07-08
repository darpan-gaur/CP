/*
https://leetcode.com/problems/path-sum-iii/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Solution 1: Map
// Time complexity: O(nlogn)
class Solution {
public:
    map<long long, int> m;
    int ans;
    long long currSum;
    void solve(TreeNode* root, int targetSum) {
        if (root == NULL) return;
        
        currSum += root->val;
        if (currSum == targetSum) ans++;
        if (m.find(currSum-targetSum)!=m.end()) ans+=m[currSum-targetSum];
        m[currSum]++;
        solve(root->left, targetSum);
        solve(root->right, targetSum);
        m[currSum]--;
        currSum -= root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        ans = 0; currSum =0;
        solve(root, targetSum);
        return ans;
    }
};

// Solution 2: path storing
// Time complexity: O(n^2)
class Solution {
public:
    vector<int> path;
    int ans;
    void solve(TreeNode* root, int targetSum) {
        if (root == NULL) return;
        path.push_back(root->val);
        solve(root->left, targetSum);
        solve(root->right, targetSum);

        long long sum=0;
        for (int i=path.size()-1;i>=0;i--) {
            sum += path[i];
            if (sum==targetSum) ans++;
        }

        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        path = {};
        solve(root, targetSum);
        return ans;
    }
};