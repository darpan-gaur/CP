/*
Linked List Class
    - insert at head
    - insert at tail
    - insert at position
    - delete a node
    - print the linked list
*/

#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

    // constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insert(Node* &head, int data, int pos) {
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
    temp1->next = temp->next;
    temp->next = temp1;
}

void insertAtTail(Node* &head, int data){
    Node* temp = head;
    Node* temp1 = new Node(data);
    if (temp == NULL) {
        head = temp1;
        return;
    }
    while (temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = temp1;
}

void Delete(Node* &head, int pos) {
    Node* temp = head;
    if (pos == 1) {
        head = temp->next;
        delete temp;
        return;
    }
    for (int i=1;i<pos-1;i++) {
        temp = temp->next;
    }
    Node *temp1 = temp->next;
    temp->next = temp1->next;
    delete temp1;
}

void print(Node* &head) {
    Node* temp = head;
    while (temp!=NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}


int main() {

    // create a node
    Node* head = NULL;

    // insert at head
    // insertAtHead(head, 5);
    // insertAtHead(head, 4);
    // insertAtHead(head, 3);
    // insertAtHead(head, 2);
    // insertAtHead(head, 1);

    // insert at position
    insert(head, 1, 1);
    insert(head, 2, 1);
    insert(head, 5, 3);
    insert(head, 4, 3);
    insert(head, 3, 3);

    // insert at tail
    // insertAtTail(head, 1);
    // insertAtTail(head, 2);
    // insertAtTail(head, 3);
    // insertAtTail(head, 4);
    // insertAtTail(head, 5);

    

    // print the linked list
    print(head);

    // delete a node
    // Delete(head, 1);

    // print the linked list
    // print(head);

    // delete a node
    // Delete(head, 3);

    // print the linked list    
    // print(head);    

    return 0;
}