/*
https://leetcode.com/problems/check-completeness-of-a-binary-tree
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

// Solution 1: BFS
// Time: O(n), Space: O(n)
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root==NULL) return true;

        bool nullFound = false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == NULL) nullFound = true;
            else {
                if (nullFound) return false;
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;

    }
};

// Solution 2: DFS
// Time: O(n), Space: O(n)
class Solution {
public:
    int cntNode(TreeNode* root) {
        if (root==NULL) return 0;
        return cntNode(root->left) + 1 + cntNode(root->right);
    }
    bool dfs(TreeNode* root, int idx, int n) {
        if (root == NULL) return true;
        // If index assigned to current node is greater or equal to the number of nodes
        // in tree, then the given tree is not a complete binary tree.
        if (idx >= n) return false;

        return dfs(root->left, 2*idx+1, n) & dfs(root->right, 2*idx+2, n);
    }
    bool isCompleteTree(TreeNode* root) {
        
        return dfs(root, 0, cntNode(root));
    }
};