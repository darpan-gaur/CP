#include <iostream>
#include <queue>

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

node* insert(node* root, int data) {
    if (root == NULL) {
        root = new node(data); 
        return root;
    }
    if (data <= root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

void buildTree(node* &root) {
    cout << "Enter data: ";
    int data;
    cin >> data;
    while (data != -1) {
        root = insert(root, data);
        cin >> data;
    }
}

node* search(node* root, int data) {
    if (root == NULL) return NULL;
    if (root->data == data) return root;
    if (data < root->data) return search(root->left, data);
    else return search(root->right, data);
}

// iterative search
node* searchIt(node* root, int data) {
    while (root != NULL) {
        if (root->data == data) return root;
        if (data < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

node* findMin(node* root) {
    if (root == NULL) return root;
    while (root->left != NULL) root = root->left;
    return root;
}

node* findMax(node* root) {
    if (root == NULL) return root;
    while (root->right != NULL) root = root->right;
    return root;
}

// inorder predecessor
void getPred(node* root, node* &pred, int data) {
    if (root == NULL) return;
    if (root->data == data) {
        if (root->left != NULL) {
            pred = findMax(root->left);
        }
    }
    else if (data < root->data) {
        getPred(root->left, pred, data);
    } 
    else {
        pred = root;
        getPred(root->right, pred, data);
    }
}

// inorder successor
void getSucc(node* root, node* &succ, int data) {
    if (root == NULL) return;
    if (root->data == data) {
        if (root->right != NULL) {
            succ = findMin(root->right);
        }
    }
    else if (data < root->data) {
        succ = root;
        getSucc(root->left, succ, data);
    } 
    else {
        getSucc(root->right, succ, data);
    }
}

// inorder predecessor and successor
void getPredSucc(node* root, node* &pred, node* &succ, int data) {
    if (root == NULL) return;
    if (root->data == data) {
        if (root->left != NULL) {
            pred = findMax(root->left);
        }
        if (root->right != NULL) {
            succ = findMin(root->right);
        }
    }
    else if (data < root->data) {
        succ = root;
        getPredSucc(root->left, pred, succ, data);
    } 
    else {
        pred = root;
        getPredSucc(root->right, pred, succ, data);
    }
}

node* Delete(node* root, int val) {
    if (root == NULL) return root;
    if (val < root->data) root->left = Delete(root->left, val);
    else if (val > root->data) root->right = Delete(root->right, val);
    else {
        // case 1: no child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        // case 2: one child
        else if (!root->left || !root->right) {
            node* temp = root->left ? root->left : root->right;
            delete root;
            root = temp;
        }
        // case 3: two children
        else {
            node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
            
            // node* temp = findMax(root->left);
            // root->data = temp->data;
            // root->left = Delete(root->left, temp->data);
        }
    }
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
    cout << endl;
}

int main() {
    node* root = NULL;
    buildTree(root);

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);

    // search
    cout << "Enter data to search: ";
    int data;
    cin >> data;
    node* result = search(root, data);
    // node* result = searchIt(root, data);
    if (result == NULL) cout << "Not found" << endl;
    else cout << "Found" << endl;

    // find min
    node* min = findMin(root);
    cout << "Min: " << min->data << endl;

    // find max
    node* max = findMax(root);
    cout << "Max: " << max->data << endl;

    // inorder predecessor
    cout << "Enter data to find predecessor: ";
    cin >> data;
    node* pred = NULL;
    getPred(root, pred, data);
    if (pred == NULL) cout << "No predecessor" << endl;
    else cout << "Predecessor: " << pred->data << endl;

    // inorder successor
    cout << "Enter data to find successor: ";
    cin >> data;
    node* succ = NULL;
    getSucc(root, succ, data);
    if (succ == NULL) cout << "No successor" << endl;
    else cout << "Successor: " << succ->data << endl;

    // inorder predecessor and successor
    cout << "Enter data to find predecessor and successor: ";
    cin >> data;
    node* predSucc = NULL;
    node* succPred = NULL;
    getPredSucc(root, predSucc, succPred, data);
    if (predSucc == NULL) cout << "No predecessor" << endl;
    else cout << "Predecessor: " << predSucc->data << endl;
    if (succPred == NULL) cout << "No successor" << endl;
    else cout << "Successor: " << succPred->data << endl;

    return 0;
}