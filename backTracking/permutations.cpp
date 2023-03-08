/* 
@darpangaur
https://leetcode.com/problems/permutations/
*/

class Solution {
public:
    void allPermutation(vector<vector<int>>& ans,vector<int>& permutation,vector<int>& chosen,vector<int> nums) {
        if (permutation.size()==nums.size()){
            ans.push_back(permutation);
            return;
        }
        for (int i=0;i<nums.size();i++){
            if (chosen[i]) continue;
            chosen[i] = 1;
            permutation.push_back(nums[i]);
            allPermutation(ans,permutation,chosen,nums);
            chosen[i] = 0;
            permutation.pop_back();
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> permutation;
        vector<int> chosen(nums.size(),0);
        allPermutation(ans,permutation,chosen,nums);
        return ans;
    }   
};