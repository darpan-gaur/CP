/*
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
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

// Solution 1 :- recursive
class Solution {
public:
    // distance -> level -> element
    // multiset for increaing order
    map<int, map<int, multiset<int>>> m;

    void solve(TreeNode* root, int dist, int level) {
        if (root == NULL) return;
        m[dist][level].insert(root->val);
        solve(root->left, dist-1, level+1);
        solve(root->right, dist+1, level+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root==NULL) return ans;
        solve(root, 0, 0);
        for (auto d:m) {
            vector<int> temp;
            for (auto l:d.second) {
                for (auto node:l.second) temp.push_back(node);
            }ans.push_back(temp);
        }
        return ans;
    }
};

// Solution 2 :- level order traversal + map
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // distance -> level -> element
        // multiset for increaing order
        map<int, map<int, multiset<int>>> m;
        vector<vector<int>> ans;
        // distance -> level
        queue<pair<TreeNode*, pair<int,int>>> q;
        if (root==NULL) return ans;
        q.push({root, {0,0}});
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            m[temp.second.first][temp.second.second].insert(temp.first->val);

            if (temp.first->left!=NULL) {
                q.push({temp.first->left, {temp.second.first-1, temp.second.second+1}});
            }
            if (temp.first->right!=NULL) {
                q.push({temp.first->right, {temp.second.first+1, temp.second.second+1}});
            }
        }
        for (auto d:m) {
            vector<int> temp;
            for (auto l:d.second) {
                for (auto node:l.second) temp.push_back(node);
            }ans.push_back(temp);
        }
        return ans;
    }
};