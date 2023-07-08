/*
Binary Tree
- create tree
- level order traversal :-  using queue
- create tree from level order
- pre order traversal :- root left right
- pre order traversal iterative     :- using stack
- pre order traversal iterative 2   :- using stack
- pre order traversal Morris        :- without using stack, without using recursion
- in order traversal :- left root right
- in order traversal iterative      :- using stack
- in order traversal Morris         :- without using stack, without using recursion
- post order traversal :- left right root
- post order traversal iterative    :- using two stacks
- post order traversal iterative 2  :- using one stack
*/

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class node {
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

void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left != NULL) {
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

void createTreeFromLevelOrder(node* &root) {
    queue<node*> q;
    cout << "Enter data for root: ";
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left child of " << temp->data << endl;
        cin >> data;
        if(data != -1) {
            temp->left = new node(data);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << endl;
        cin >> data;
        if(data != -1) {
            temp->right = new node(data);
            q.push(temp->right);
        }
        
    }
}

void preOrderTraversal(node* root) {
    // root left right
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// iterative pre order traversal
void preOrderTraversalIterative(node* root) {
    stack<node*> s;
    s.push(root);
    while (!s.empty()) {
        node* temp = s.top();
        s.pop();
        cout << temp->data << " ";
        if(temp->right != NULL) {
            s.push(temp->right);
        }
        if(temp->left != NULL) {
            s.push(temp->left);
        }
    }
}

// iterative pre order traversal
// not pushing left child in stack
// Time complexity: O(n), Space complexity: O(h) where h is height of tree
void preOrderTraversalIterative2(node* root) {
    stack<node*> s;
    node* curr = root;
    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            cout << curr->data << " ";
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        curr = curr->right;
    }
}

// iterative pre order traversal :- Morris Traversal
// without using stack, without using recursion
// Time complexity: O(n), Space complexity: O(1)
void preOrderTraversalMorris(node* root) {
    node* curr = root;
    while (curr != NULL) {
        // if left child is NULL
        // print the node and move to right child
        if (curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right;
        } else {
            // INORDER PREDECESSOR - rightmost node in left subtree
            // find inorder predecessor of curr
            node* temp = curr->left;
            while (temp->right != NULL && temp->right != curr) {
                temp = temp->right;
            }

            // if right child is NULL
            // create a link from inorder predecessor to curr
            // print the node and move to left child
            if (temp->right == NULL) {
                cout << curr->data << " ";
                temp->right = curr;
                curr = curr->left;
            } 
            // if right child is not NULL
            // remove the link and move to right child
            else {
                temp->right = NULL;
                curr = curr->right;
            }
        }
    }
}

void inOrderTraversal(node* root) {
    // left root right
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// iterative in order traversal
// Time complexity: O(n), Space complexity: O(h) where h is height of tree
void inOrderTraversalIterative(node* root) {
    stack<node*> s;
    node* curr = root;
    while (curr != NULL || !s.empty()) {
        // push all left child in stack
        // reach leftmost node
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }

        // backtrack to parent node
        // print the node
        // move to right child
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

// iterative in order traversal :- Morris Traversal
// without using stack, without using recursion
// Time complexity: O(n), Space complexity: O(1)
void inOrderTraversalMorris(node* root) {
    node* curr = root;
    while (curr != NULL) {
        // if left child is NULL
        // print the node and move to right child
        if (curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right;
        } else {
            // INORDER PREDECESSOR - rightmost node in left subtree
            // find inorder predecessor of curr
            node* temp = curr->left;
            while (temp->right != NULL && temp->right != curr) {
                temp = temp->right;
            }

            // if right child is NULL
            // create a link from inorder predecessor to curr
            if (temp->right == NULL) {
                temp->right = curr;
                curr = curr->left;
            } 
            // if right child is not NULL
            // remove the link, print the node and move to right child, 
            else {
                temp->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

void postOrderTraversal(node* root) {
    // left right root
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// iterative post order traversal :- using two stacks
// Time complexity: O(n), Space complexity: O(n)
void postOrderTraversalIterative(node* root) {
    stack<node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        node* temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left != NULL) {
            s1.push(temp->left);
        }
        if(temp->right != NULL) {
            s1.push(temp->right);
        }
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// iterative post order traversal :- using one stack
// Time complexity: O(n), Space complexity: O(h) where h is height of tree
void postOrderTraversalIterative2(node* root) {
    stack<node*> s;
    node* curr = root;
    node* prev = NULL;
    while (curr != NULL || !s.empty()) {
        // push all left child in stack
        // reach leftmost node
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }

        // backtrack to parent node
        // if right child is NULL or visited
        // print the node, pop the node, mark it as visited
        curr = s.top();
        if (curr->right == NULL || curr->right == prev) {
            cout << curr->data << " ";
            s.pop();
            prev = curr;
            curr = NULL;
        }
        // if right child is not NULL
        // move to right child
        else {
            curr = curr->right;
        }
    }
}

int main() {
    node* root = NULL;
    // root = createTree(root);
    createTreeFromLevelOrder(root);
    // 1 2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 -1 -1 7 -1 -1

    cout << "Level order traversal: ";
    levelOrderTraversal(root);

    cout << "\nPre order traversal: ";
    preOrderTraversal(root);

    cout << "\nPre order traversal iterative: ";
    preOrderTraversalIterative(root);

    cout << "\nPre order traversal iterative 2: ";
    preOrderTraversalIterative2(root);

    cout << "\nPre order traversal Morris: ";
    preOrderTraversalMorris(root);

    cout << "\nIn order traversal: ";
    inOrderTraversal(root);

    cout << "\nIn order traversal iterative: ";
    inOrderTraversalIterative(root);

    cout << "\nIn order traversal Morris: ";
    inOrderTraversalMorris(root);

    cout << "\nPost order traversal: ";
    postOrderTraversal(root);

    cout << "\nPost order traversal iterative: ";
    postOrderTraversalIterative(root);

    cout << "\nPost order traversal iterative 2: ";
    postOrderTraversalIterative2(root);

    return 0;
}