/*
https://leetcode.com/problems/rotate-array/
*/

// Solution 1
// Time Complexity: O(n), Space Complexity: O(1)
class Solution {
public:
    void reverse(vector<int>& nums, int i, int j) {
        for (;i<=j;) swap(nums[i++], nums[j--]);
    }
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        reverse(nums, 0, nums.size()-k-1);
        reverse(nums, nums.size()-k, nums.size()-1);
        reverse(nums, 0, nums.size()-1);
    }
};

// Solution 2
// Time Complexity: O(n), Space Complexity: O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int i, n=nums.size();
        k = k%n;
        vector<int> v = nums;
        for (i=0;i<n;i++) nums[(i+k)%n] = v[i];
    }
};