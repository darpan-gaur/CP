/*
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

// Time: O(logn), space: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int a = 0,b = nums.size()-1,mid;
        while (a <= b) {
            
            mid = a + (b-a)/2;
            if (nums[mid]==target) return mid;
            if (nums[mid]>=nums[a]) {
                if (nums[a]<=target && target<=nums[mid]) b = mid-1;
                else a = mid+1; 
            }
            else {
                if (nums[b]>=target && target>=nums[mid]) a = mid+1;
                else b = mid-1;
            }
            cout << a << " " << b << " "<< mid << "\n";
            
        }
        return -1;
    }
};