/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
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
// Time complexity: O(nlogn), Space complexity: O(n)
class Solution {
public:
    map<int,int> m;
    TreeNode* solve(int& i, int inSt, int inEn, vector<int>& preorder, vector<int>& inorder) {
        if (i >= preorder.size() || inSt>inEn) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        int pos = m[preorder[i++]];

        root->left = solve(i, inSt, pos-1, preorder, inorder);
        root->right = solve(i, pos+1, inEn, preorder, inorder);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;
        for (i=0;i<preorder.size();i++) {
            m[inorder[i]] = i;
        }
        i=0;
        return solve(i, 0, preorder.size()-1, preorder, inorder);
    }
};

// Solution 2 , easy to understand
// Time complexity: O(nlogn), Space complexity: O(n)
class Solution {
public:
    map<int,int> m;
    TreeNode* solve(int& i, int inSt, int inEn, vector<int>& preorder, vector<int>& inorder) {
        if (i >= preorder.size() || inSt>inEn) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        int pos = m[preorder[i++]];

        root->left = solve(i, inSt, pos-1, preorder, inorder);
        root->right = solve(i, pos+1, inEn, preorder, inorder);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;
        for (i=0;i<preorder.size();i++) {
            m[inorder[i]] = i;
        }
        i=0;
        return solve(i, 0, preorder.size()-1, preorder, inorder);
    }
};