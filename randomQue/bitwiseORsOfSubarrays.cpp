/*
https://leetcode.com/problems/bitwise-ors-of-subarrays/
*/

// solution 1 
// Time complexity: O(nlogW), where W is the maximum value of A[i]
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> prev;
        set<int> ans;
        prev.insert(arr[0]);
        ans.insert(arr[0]);
        for (int i=1;i<arr.size();i++) {
            set<int> curr;
            for (auto x:prev) {
                curr.insert(x|arr[i]);
                ans.insert(x|arr[i]);
                curr.insert(arr[i]);
                ans.insert(arr[i]);
            }
            prev = curr;
        }
        return ans.size();
    }
};