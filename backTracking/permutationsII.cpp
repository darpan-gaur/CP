/*
https://leetcode.com/problems/permutations-ii/
*/

// Solution 1
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> permutation;
    void allPermutations(map<int,int>& chosen,vector<int>& nums){
        if (permutation.size()==nums.size()){
            ans.push_back(permutation);
            return;
        }
        for (auto& x:chosen) {
            cout << x.first << " " << x.second << "\n";
            if (x.second>0){
                x.second--;
                permutation.push_back(x.first);
                allPermutations(chosen,nums);
                x.second++;
                permutation.pop_back();
            }
            
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int,int> chosen;
        for (auto x:nums) chosen[x]++;
        allPermutations(chosen,nums);
        return ans;
    }
};

// Solution 2
class Solution {
public:
    void allPermutations(set<vector<int>>& s,vector<int>& chosen,vector<int>& nums,vector<int> permutation){
        if (permutation.size()==nums.size()){
            s.insert(permutation);
            return;
        }
        for (int i=0;i<nums.size();i++) {
            if (chosen[i]) continue;
            chosen[i] = 1;
            permutation.push_back(nums[i]);
            allPermutations(s,chosen,nums,permutation);
            chosen[i] = 0;
            permutation.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> chosen(nums.size(),0);
        vector<int> permutation;
        allPermutations(s,chosen,nums,permutation);
        for (auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};