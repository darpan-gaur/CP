/*
https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
*/

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// Solution 1
// Time :- O(n), Space :- O(n)
int cntNodes(struct Node* root) {
    if (root==NULL) return 0;
    return cntNodes(root->left) + 1 + cntNodes(root->right);
}

bool isCBT(struct Node* root, int index, int n) {
    if (root == NULL ) return true;
    if (index >= n) return false;
    
    return isCBT(root->left, 2*index+1, n) & isCBT(root->right, 2*index+2, n);
}

bool isMaxOrder(struct Node* root) {
    // leaf node 
    if (root->left == NULL && root->right == NULL) return true;
    
    if (root->right==NULL) return (root->left->data < root->data);
    
    bool left = isMaxOrder(root->left);
    bool right = isMaxOrder(root->right);
    
    return left && right && (root->left->data < root->data) && (root->right->data < root->data);
}

class Solution {
  public:
    bool isHeap(struct Node* root) {
        return isCBT(root, 0, cntNodes(root)) && isMaxOrder(root);
    }
};