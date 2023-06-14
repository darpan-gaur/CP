/*
https://leetcode.com/problems/combination-sum-iv/
*/

// Solution 1: O(n*target) time, O(target) space
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> ans(target+1,0);
        ans[0] = 1;
        for (int i=1;i<=target;i++) {
            for (auto x:nums) {
                if (i-x>=0 && ans[i]<=INT_MAX-ans[i-x]) ans[i] += ans[i-x];
            }
        }
        return ans[target];
    }
};