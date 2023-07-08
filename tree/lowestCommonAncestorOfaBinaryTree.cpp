/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Solution 1: Recursive
// Time complexity: O(n), Space complexity: O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;

        if (root==p || root==q) return root;

        TreeNode* leftPart = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightPart = lowestCommonAncestor(root->right, p, q);

        if (leftPart!=NULL && rightPart!=NULL) return root;
        else if (leftPart==NULL && rightPart!=NULL) return rightPart;
        else if (leftPart!=NULL && rightPart==NULL) return leftPart;
        else return NULL;
    }
};