/*
https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049

Time Complexity: O(N)
Space Complexity: O(1)

where N is the number of nodes in the linked list
*/

/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

// Solution
Node* detectCycle(Node* head) {
    if (head == NULL) return head;
    Node* slow = head;
    Node* fast = head;
    while (fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            return slow;
        }
    }
    return NULL;
}

Node* getCycleHead(Node* head ) {
    if (head == NULL) return head;
    Node* inter = detectCycle(head);
    if (inter==NULL) return NULL;
    Node* slow = head;
    while (slow!=inter) {
        slow = slow->next;
        inter = inter->next;
    }
    return slow;
}

Node *removeLoop(Node *head)
{
    if (head == NULL) return head;
    Node* stPt = getCycleHead(head);
    if (stPt==NULL) return head;
    Node* temp = stPt;
    while (temp->next != stPt) {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}