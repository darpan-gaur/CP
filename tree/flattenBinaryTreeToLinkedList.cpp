/*
https://leetcode.com/problems/flatten-binary-tree-to-linked-list
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

// Solution 1: Iterative
// Time complexity: O(n), Space complexity: O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr!=NULL) {
            if (curr->left == NULL) {
                curr = curr->right;
            }
            else {
                TreeNode* temp = curr->left;
                while (temp->right) {
                    temp = temp->right;
                }

                temp->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
        }
    }
};

// Solution 2: Recursive
// Time complexity: O(n), Space complexity: O(h) where h is height of tree
class Solution {
public:
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};