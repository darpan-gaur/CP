/*
Doubly Linked List Class
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // constructor
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(Node* &head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    if (head != NULL)
    {
        head->prev = temp;
    }
    head = temp;
}

void inset(Node* &head, int data, int pos) {
    Node* temp = head;
    Node* temp1 = new Node(data);
    if (pos == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }
    for (int i=1;i<pos-1;i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        temp->next = temp1;
        temp1->prev = temp;
        return;
    }
    temp1->next = temp->next;
    temp->next = temp1;
    temp1->prev = temp;
    temp1->next->prev = temp1;
}

void Delete(Node* &head, int pos) {
    Node* temp=head;
    if (pos==1) {
        head = temp->next;
        head->prev = NULL;
        delete temp;
        return;
    }
    for (int i=1;i<pos-1;i++) {
        temp = temp->next;
    }
    if (temp->next->next == NULL) {
        Node* temp1 = temp->next;
        temp->next = NULL;
        delete temp1;
        return;
    }
    Node* temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next->prev = temp;
    delete temp1;
}

// traverse the linked list
void print(Node* &head) {
    Node* temp = head;
    while (temp!=NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;
    print(head);

    // insert at head
    insertAtHead(head, 20);
    insertAtHead(head, 10);
    insertAtHead(head, 5);
    insertAtHead(head, 1);
    print(head);
    
    // insert at position
    inset(head, 15, 3);
    print(head);
    inset(head, 25, 6);
    print(head);

    // delete a node
    Delete(head, 1);
    print(head);
    Delete(head, 3);
    print(head);
    Delete(head, 4);
    print(head);
    return 0;
}

