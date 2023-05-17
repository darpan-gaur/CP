/*
Link :- https://leetcode.com/problems/coin-change/

Time Complexity = O((no of coins)*amount), Space Complexity = O(amount)
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(),i,j;
        vector<int> v(amount+1,-1);
        v[0] = 0;
        for (i=1;i<=amount;i++) {
            v[i] = INT_MAX-1;
            for (auto j:coins) {
                if (i-j>=0) {
                    v[i] = min(v[i], 1+v[i-j]);
                }
            }
        }
        if (v[amount]==INT_MAX-1) return -1;
        return v[amount];
    }
};