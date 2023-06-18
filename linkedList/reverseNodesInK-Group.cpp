/*
https://leetcode.com/problems/reverse-nodes-in-k-group/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Solurion 
// Time Complexity: O(n), Space Complexity: O(1)
class Solution {
public:
    ListNode* reverseK(ListNode* head, int k, int len) {
        if (head==NULL || len<k) return head;
        int ct=0;
        ListNode *prev = NULL, *curr = head, *aft;
        while (curr!=NULL && ct<k) {
            aft = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aft;
            ct++;
        }
        head->next = reverseK(curr, k, len-k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       if (head == NULL) return head;
       int len=0;
       ListNode* temp = head;
       while (temp!=NULL) {
           len++;
           temp = temp->next;
       } 
       return reverseK(head, k, len);
    }
};