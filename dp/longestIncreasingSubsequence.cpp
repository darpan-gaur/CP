/*
https://leetcode.com/problems/longest-increasing-subsequence/
*/

// Method 1
// Time Complexity: O(n^2), Space Complexity: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(),i,j,ans=0;
        vector<int> v(n);
        for (i=0;i<n;i++) {
            v[i] = 1;
            for (j=0;j<i;j++) {
                if (nums[i] > nums[j]) v[i] = max(v[i], v[j]+1);
            }
            ans = max(ans,v[i]);
        }
        return ans;
    }
};

// Method 2 github copilot suggested
// Time Complexity: O(nlogn), Space Complexity: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(),i,ans=0;
        vector<int> v;
        for (i=0;i<n;i++) {
            auto it = lower_bound(v.begin(),v.end(),nums[i]);
            if (it==v.end()) v.push_back(nums[i]);
            else *it = nums[i];
        }
        return v.size();
    }
};

// Method 3
// Time Complexity: O(nlogn), Space Complexity: O(1)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=0;
        for (auto x:nums) {
            if (len==0 || nums[len-1] < x) nums[len++] = x;             // extend
            else *lower_bound(nums.begin(), nums.begin()+len, x) = x;   // replace
        }
        return len;
    }
};