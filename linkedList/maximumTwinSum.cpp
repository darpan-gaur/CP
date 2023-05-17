/*
https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
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

// Method 1
// Time : - O(n), Space : - O(n)
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *temp;
        temp = head;
        int i,n=0,ans=0;
        while (temp!=NULL) {
            n++;
            temp = temp->next;
        }
        temp = head;
        vector<int> v(n/2);
        for (i=0;i<n/2;i++) {
            v[i] = temp->val;
            temp = temp->next;
        }
        for (i=0;i<n/2;i++) {
            v[n/2-1-i] += temp->val;
            ans = max(ans, v[n/2-i-1]);
            temp = temp->next; 
        }
        return ans;
    }
};

// Method 2 : - Stack
// Time : - O(n), Space : - O(n)
/*
--> Push first half of linked list in stack
--> Traverse second half of linked list and pop from stack
--> Add popped element and current element and update ans
*/

// Method 3 : - Reverse the second half of the linked list
// Time : - O(n), Space : - O(1)
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow=head, *fast=head;
        int ans=0;

        // get middle of linked list
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse the second half of linked list
        ListNode *nextNode, *prev = NULL;
        while (slow) {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        slow = head;
        while (prev) {
            ans = max(ans, slow->val + prev->val);
            slow = slow->next;
            prev = prev->next;
        }

        return ans;
    }
};