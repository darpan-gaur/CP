/*
https://leetcode.com/problems/unique-binary-search-trees-ii/
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

// solution 1 :- recursive
class Solution {
public:
    vector<TreeNode*> solve(int low, int high) {
        vector<TreeNode*> res;
        if (low>high) {
            res.push_back(NULL);
            return res;
        }
        for (int i=low;i<=high;i++) {
            vector<TreeNode*> leftSub = solve(low, i-1);
            vector<TreeNode*> rightSub = solve(i+1, high);

            for (int j=0;j<leftSub.size();j++) {
                for (int k=0;k<rightSub.size();k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftSub[j];
                    root->right = rightSub[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};