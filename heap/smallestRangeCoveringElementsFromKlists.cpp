/*
https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
*/

// Solution 1: Using heap
// Time Complexity: O(nlogk), Space Complexity: O(k)
class Solution {
    class node{
        public:
            int data;
            int i;
            int j;
        node (int data, int i, int j) {
            this->data = data;
            this->i = i;
            this->j = j;
        }
    };
    class cmp{
        public:
            bool operator() (node* a, node* b) {
                return a->data > b->data;
            }
    };
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int Max = INT_MIN, Min = INT_MAX, k= nums.size(), i;
        priority_queue<node*, vector<node*>, cmp> q;
        for (i=0;i<k;i++) {
            node* temp = new node(nums[i][0], i, 0);
            Min = min(Min, temp->data);
            Max = max(Max, temp->data);
            q.push(temp);
        }
        int st = Min, en = Max;
        while (!q.empty()) {
            node* temp = q.top();
            q.pop();
            Min = temp->data;
            
            if (Max - Min < en - st) {
                st = Min;
                en = Max;
            }

            if (temp->j + 1 < nums[temp->i].size()) {
                node* temp2 = new node(nums[temp->i][temp->j+1], temp->i, temp->j+1);
                Max = max(Max, temp2->data);
                q.push(temp2);
            }
            else break;
        }
        return {st, en};
    }
};