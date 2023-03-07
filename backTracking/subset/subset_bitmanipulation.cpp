// Bit manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size(),i,j;
        vector<vector<int>> ans;
        for (j=0;j<(1<<n);j++){
            vector<int> subset;
            for (i=0;i<n;i++){
                if (j&(1<<i)) subset.push_back(nums[i]);
            }
            ans.push_back(subset);
        }return ans;
    }
};