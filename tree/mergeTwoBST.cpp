/*
https://www.codingninjas.com/studio/problems/h_920474
*/

// Solution 1 :- inorder traversal + build tree
// TC: O(N), SC: O(N)
void trav(TreeNode<int>* root, vector<int> &v) {
    if (root==NULL) return;
    trav(root->left, v);
    v.push_back(root->data);
    trav(root->right, v);
}

TreeNode<int>* balance(int a, int b, vector<int>& inorder) {
    if (a>b) return NULL;
    int mid = a+(b-a)/2;
    TreeNode<int> *root = new TreeNode<int>(inorder[mid]);
    root->left = balance(a, mid-1, inorder);
    root->right = balance(mid+1, b, inorder);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> in1, in2;
    trav(root1, in1);
    trav(root2, in2);

    // merge in1 & in2
    vector<int> v;
    int i=0, j=0;
    while (i<in1.size() && j<in2.size()) {
        if (in1[i] < in2[j]) {
            v.push_back(in1[i++]);
        }else v.push_back(in2[j++]);
    }
    while (i<in1.size()) v.push_back(in1[i++]);
    while (j<in2.size()) v.push_back(in2[j++]);

    // make bst from inorder
    return balance(0, v.size()-1, v);
}

// Solution 2 :- double linked list -> merge -> bst
// TC: O(N), SC: O(h)
void convertIntoSortedDLL(TreeNode<int>* root, TreeNode<int>* &head) {
    // Time:- O(n), Space:- O(h)
    if (root == NULL) return;

    convertIntoSortedDLL(root->right, head);
    
    root->right = head;

    if (head!=NULL) head->left = root;
    
    head = root;

    convertIntoSortedDLL(root->left, head);    
}

TreeNode<int>* mergeLL(TreeNode<int>* head1, TreeNode<int>* head2) {
    TreeNode<int>* head = NULL;
    TreeNode<int>* tail = NULL;
    
    while (head1!=NULL && head2!=NULL) {
        if (head1->data < head2->data) {
            if (head==NULL) {
                head = head1;
                tail = head1;
                head1 = head1->right;    
            }
            else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else {
            if (head==NULL) {
                head = head2;
                tail = head2;
                head2 = head2->right; 
            }else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    
    while (head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int findLen(TreeNode<int>* root) {
    int cnt = 0;
    while (root!=NULL) {
        root = root->right;
        cnt++;
    }
    return cnt;
}

TreeNode<int>* sortedLLtoBST(TreeNode<int>* &head, int n) {
    if (n<=0 || head==NULL) return NULL;
    
    TreeNode<int> *left = sortedLLtoBST(head, n/2);

    TreeNode<int> *root = head;
    root->left = left;
    
    head = head->right;
    
    root->right = sortedLLtoBST(head, n-n/2-1);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    
    // convert BST into sorted DLL- inplace
    TreeNode<int> *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode<int> *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    // merge sorted LL
    TreeNode<int> *head =  mergeLL(head1, head2);
    
    // convert LL to BST
    return sortedLLtoBST(head, findLen(head));
}