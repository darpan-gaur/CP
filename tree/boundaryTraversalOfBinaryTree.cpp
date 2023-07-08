/*
https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
*/

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */


// Solution 1
class Solution {
public:
    vector<int> ans;
    void getLeft(Node* root) {
        if ((root==NULL) || (root->left==NULL && root->right==NULL)) return;
        ans.push_back(root->data);
        if (root->left) {
            getLeft(root->left);
        }else getLeft(root->right);
    }
    
    void inorder(Node* root){
        if (root==NULL) return;
        inorder(root->left);
        if (root->left==NULL && root->right==NULL) {
            ans.push_back(root->data);
        }
        inorder(root->right);
    }
    
    void getRight(Node* root) {
        if ((root==NULL) || (root->left==NULL && root->right==NULL)) return;
        if (root->right) {
            getRight(root->right);
        }else getRight(root->left);
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        if (root == NULL) return ans;
        
        ans.push_back(root->data);
        
        // get left
        getLeft(root->left);
        
        // get leaf nodes
        inorder(root->left);
        inorder(root->right);
            
        // get right
        getRight(root->right);
        
        return ans;
        
    }
};