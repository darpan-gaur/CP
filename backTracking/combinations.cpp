/*
https://leetcode.com/problems/combinations
*/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> combination;
    void allCombinations(int i,int temp,int k,int n){
        if (combination.size()==k) {
            ans.push_back(combination);
            return;
        }
        if (i==n+1) return;
        if (temp>0) {
            temp--;
            combination.push_back(i);
            allCombinations(i+1,temp,k,n);
        }
        temp++;
        combination.pop_back();
        allCombinations(i+1,temp,k,n);
    }
    vector<vector<int>> combine(int n, int k) {
        allCombinations(1,k,k,n);
        return ans;
    }
};