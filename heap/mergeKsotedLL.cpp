/*
https://leetcode.com/problems/merge-k-sorted-lists/
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

// Solution 1: Using priority queue
// Time complexity: O(N*klogk), Space complexity: O(k)
class Solution {
    class cmp{
        public:
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;
            }     
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size(),i;
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        
        ListNode* head = NULL;
        ListNode* tail = NULL;

        for (i=0;i<k;i++) {
            if (lists[i]!=NULL) q.push(lists[i]);
        }

        while (q.size()) {
            ListNode* temp = q.top();
            q.pop();

            if (temp->next!=NULL) {
                q.push(temp->next);
            } 

            if (head == NULL) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }

            
        }
        return head;
    }
};