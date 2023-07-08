/*
https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
*/

// Solution 1
// Time Complexity: O(n),   Space Complexity: O(1)
class Solution
{
    public:
    // insert at tail
    void inTail(Node* &tail, Node* &head, int data){
        Node* temp = new Node(data);
        if (tail==NULL) {
            tail = temp;
            head = temp;
        }else {
            tail->next = temp;
            tail = temp; 
        }
    }
    Node *copyList(Node *head)
    {   
        // next pointer clone
        Node *cHead=NULL, *cTail=NULL;
        Node *temp = head;
        while (temp!=NULL) {
            inTail(cTail, cHead, temp->data);
            temp = temp->next;
        }
        
        temp = head;
        Node* ctemp = cHead;
        Node* temp2;
        while (temp!=NULL && ctemp!=NULL) {
            temp2 = temp->next;
            temp->next = ctemp;
            temp = temp2;
            
            temp2 = ctemp->next;
            ctemp->next = temp;
            ctemp = temp2;
        }
        
        // arb pointer setting
        temp = head;
        while (temp!=NULL) {
            if (temp->next!=NULL){
                temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
            }
            temp = temp->next->next;
        }
        
        temp = head;
        ctemp = cHead;
        while (temp!=NULL && ctemp!=NULL) {
            temp->next = ctemp->next;
            temp = temp->next;
            
            if (temp!=NULL) ctemp->next = temp->next;
            ctemp = ctemp->next;
        }
        
        return cHead;
    }

};

// Solution 2
// Time Complexity: O(n),   Space Complexity: O(n)
class Solution
{
    public:
    // insert at tail
    void inTail(Node* &tail, Node* &head, int data){
        Node* temp = new Node(data);
        if (tail==NULL) {
            tail = temp;
            head = temp;
        }else {
            tail->next = temp;
            tail = temp; 
        }
    }
    Node *copyList(Node *head)
    {   
        // next pointer clone
        Node *cHead=NULL, *cTail=NULL;
        Node *temp = head;
        while (temp!=NULL) {
            inTail(cTail, cHead, temp->data);
            temp = temp->next;
        }
        
        // arb clone
        unordered_map<Node*, Node*> m;
        temp = head;
        Node* ctemp = cHead;
        while (temp!=NULL && ctemp!=NULL) {
            m[temp] = ctemp;
            temp = temp->next;
            ctemp = ctemp->next;
        }
        
        temp = head;
        ctemp = cHead;
        while (temp!=NULL && ctemp!=NULL) {
            ctemp->arb = m[temp->arb];
            temp = temp->next;
            ctemp = ctemp->next;
        }
        
        return cHead;
    }

};