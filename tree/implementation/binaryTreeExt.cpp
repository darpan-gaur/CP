#include <iostream>

using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    // constructor
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* createTree(node* root) {
    cout << "Enter data: ";
    int data;
    cin >> data;
    if(data == -1) {    // assums -1 as NULL
        return NULL;
    }
    root = new node(data);

    cout << "Enter left child of " << data << endl;
    root->left = createTree(root->left);

    cout << "Enter right child of " << data << endl;
    root->right = createTree(root->right);

    return root;
}

// height of a tree
int height(node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// diameter of a tree

// Time complexity: O(n^2), Space complexity: O(h) where h is height of tree
int diameter(node* root) {
    if(root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

// Time complexity: O(n), Space complexity: O(h) where h is height of tree
class Pair {
    public:
        int height;
        int diameter;
};
Pair fastDiameter(node* root) {
    Pair p;
    if(root == NULL) {
        p.height = p.diameter = 0;
        return p;
    }
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);
    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height + 1, max(left.diameter, right.diameter));
    return p;
}
int fastDiameterOfTree(node* root) {
    Pair p = fastDiameter(root);
    return p.diameter;
}





int main() {
    node* root = NULL;
    root = createTree(root);
    // 1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    cout << "Height of tree: " << height(root) << endl;

    cout << "Diameter of tree: " << diameter(root) << endl;

    cout << "Fast diameter of tree: " << fastDiameterOfTree(root) << endl;

    return 0;
}