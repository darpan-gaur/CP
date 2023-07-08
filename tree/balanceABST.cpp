/*
https://leetcode.com/problems/balance-a-binary-search-tree/
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

// Solution 1: inorder traversal + build tree
// TC: O(N), SC: O(N)
class Solution {
public:
    vector<int> inorder;
    void tra(TreeNode* root) {
        if (root == NULL) return;
        tra(root->left);
        inorder.push_back(root->val);
        tra(root->right);
    }
    TreeNode* balance(int a, int b) {
        if (a>b) return NULL;
        int mid = a+(b-a)/2;
        TreeNode *root = new TreeNode(inorder[mid]);
        root->left = balance(a, mid-1);
        root->right = balance(mid+1, b);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder = {};
        tra(root);
        return balance(0, inorder.size()-1);
    }
};