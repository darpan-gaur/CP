/*
https://leetcode.com/problems/partition-equal-subset-sum/

*/

// Solution 1: dynamic programming
// Time complexity: O(n*sum)
// Space complexity: O(n*sum)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0,i,j;
        for (i=0;i<n;i++) sum += nums[i];
        if (sum & 1) return false;
        sum = sum/2;
        vector<vector<bool>> v(n+1, vector<bool> (sum+1));
        for (i=0;i<=sum;i++) v[0][i] = 0;
        for (i=0;i<=n;i++)   v[i][0] = 1;
        for (i=1;i<=n;i++) {
            for (j=1;j<=sum;j++) {
                if (nums[i-1]<=j) v[i][j] = (v[i-1][j-nums[i-1]])||(v[i-1][j]);
                else v[i][j] = v[i-1][j];
            }
        }
        return v[n][sum];
    }
};

// Solution 2: bit manipulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=0;
        for (int x:nums) total += x;
        if (total & 1) return false;
        bitset<10001> sum(1);
        for (int x:nums) {
            sum |= sum << x;
        }
        return sum[total/2];
    }
};