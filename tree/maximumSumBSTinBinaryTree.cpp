/*
https://leetcode.com/problems/maximum-sum-bst-in-binary-tree
*/

// Solution 1: O(n) time, O(n) space
// slightly faster than solution 2
class NodeValue{
  public: 
    int maxValue;
    int minValue;
    int nodeSum;
    NodeValue(int min, int max, int sum){
        maxValue = max;
        minValue = min;
        nodeSum = sum;
    }
};

class Solution {
public:
    int ans = 0;
    NodeValue largestBSTHelper(TreeNode* root){
        if(!root) return NodeValue(INT_MAX,INT_MIN,0);
        
        auto left = largestBSTHelper(root->left);
        auto right = largestBSTHelper(root->right);
        
        if(left.maxValue < root->val && right.minValue > root->val){

            int curr_sum = root->val + left.nodeSum + right.nodeSum;
            ans = max(ans,curr_sum);

            return NodeValue(min(left.minValue,root->val),max(root->val,right.maxValue),curr_sum);
        }
        else
            return NodeValue(INT_MIN,INT_MAX,0);
    }

    int maxSumBST(TreeNode* root) {
        largestBSTHelper(root);
        root->left = nullptr;
        root->right = nullptr;
        return ans;
    }
};

// Solution 2: O(n) time, O(n) space
class Solution {
private:
    class AddOn{
        public:
            int minVal;
            int maxVal;
            bool isBST;
            int summ;
    };
public:
    int ans;
    AddOn solve(TreeNode* root) {
        if (root == NULL) return {INT_MAX, INT_MIN, true, 0};
        AddOn left = solve(root->left);
        AddOn right = solve(root->right);

        AddOn curr;
        curr.minVal = min(root->val, left.minVal);
        curr.maxVal = max(root->val, right.maxVal);
        curr.isBST = left.isBST && right.isBST && ((root->val > left.maxVal) && (root->val < right.minVal));
        curr.summ = left.summ + root->val + right.summ;

        if (curr.isBST) ans = max(ans, curr.summ);

        return curr;
    }
    int maxSumBST(TreeNode* root) {
        ans = 0;
        AddOn temp = solve(root);
        return ans;
    }
};