/*
https://leetcode.com/problems/swap-nodes-in-pairs/

Time Complexity: O(n)
Space Complexity: O(1)
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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *tempPrev,*temp,*tempNext;
        if (head==NULL || head->next==NULL) return head;
        tempPrev = head;
        temp = head;
        tempNext = temp->next;
        
        temp->next = tempNext->next;
        tempNext->next = temp;
        head = tempNext;
        
        while (true) {
            tempPrev = temp;
            if (temp->next==NULL) break;
            if (temp->next->next==NULL) break;
            temp = temp->next;
            tempNext = temp->next;
            
            temp->next = tempNext->next;
            tempNext->next = temp;
            tempPrev->next = tempNext;
        }
        return head;
    }
};