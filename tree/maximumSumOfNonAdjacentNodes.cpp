/*
https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
*/

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/


// Solution 1
// Time Complexity O(n), Space Complexity O(n)
class Solution{
  public:
    // takin , not-taking
    pair<int,int> solve(Node* root) {
        if (root == NULL) return {0,0};
        
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        pair<int,int> ans;
        ans.first = left.second + root->data + right.second;
        ans.second = max(left.first, left.second) + max(right.first, right.second);
        return ans;
    }
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);
        
    }
};