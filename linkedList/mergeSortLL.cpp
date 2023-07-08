/*
https://www.codingninjas.com/codestudio/problems/mergesort-linked-list_630514
*/

/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/

node* getMid(node* head) {
    node *slow = head, *fast = head->next;
    while (fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node *left, node *right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    node* ans = new node(0);
    node* temp = ans;

    while (left!=NULL && right!=NULL) {
        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        }else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left!=NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right!=NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

node* mergeSort(node *head) {
    if (head == NULL || head->next==NULL) return head;

    // find mid
    node *mid = getMid(head);

    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    // sort left and right part
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both
    node *ans= merge(left, right);

    return ans;
}
