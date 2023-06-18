/*
https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332
*/

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int>* merge(Node<int>* first, Node<int>*second){
    Node<int> *temp1 = first, *t1_next = first->next;
    Node<int> *temp2 = second,  *t2_next = second->next;

    if (t1_next==NULL) {
        temp1->next = temp2;
        return first;
    }

    while (t1_next!=NULL && temp2!=NULL) {
        if ((temp2->data >= temp1->data) && (temp2->data <= t1_next->data)) {
            temp1->next = temp2;
            t2_next = temp2->next;
            temp2->next = t1_next;

            temp1 = temp2;
            temp2 = t2_next;
        }
        else {
            temp1 = t1_next;
            t1_next = t1_next->next;

            if (t1_next==NULL) {
                temp1->next = temp2;
                return first;
            }
        }
    }
    return first;
}


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if (first == NULL) return second;
    if (second == NULL) return first;

    if (first->data <= second->data) {
        return merge(first, second);
    }
    return merge(second, first);
    
}
