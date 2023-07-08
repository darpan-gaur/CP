/*
https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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

// Solution 1  
// Time complexity: O(n), Space complexity: O(n)
class Solution {
public:
    TreeNode* solve(int low, int high, vector<int>& preorder, int &idx) {
        if (idx >= preorder.size()) return NULL;
        if (preorder[idx]<low || preorder[idx]>high) return NULL;
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        root->left = solve(low, preorder[idx-1], preorder, idx);
        root->right = solve(preorder[idx-1], high, preorder, idx);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return solve(INT_MIN, INT_MAX, preorder, idx);
    }
};
