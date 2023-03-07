// Backtracking 
class Solution {
public:
    void subset(vector<vector<int>>& s,vector<int> nums,vector<int>& v,int n){
            if (n==0) {
                s.push_back(v);
                return;
            }
            subset(s,nums,v,n-1);
            v.push_back(nums[n-1]);
            subset(s,nums,v,n-1);
            v.pop_back();
        }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> s;
        vector<int> v;
        subset(s,nums,v,nums.size());
        return s;
    }
};


