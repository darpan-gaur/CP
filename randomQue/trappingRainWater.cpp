/*
https://leetcode.com/problems/trapping-rain-water/
*/

// Method 1
// Time complexity: O(n), Space complexity: O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans=0, i, temp;
        vector<int> v(n);
        v[n-1] = height[n-1];
        for (i=n-2;i>0;i--) {
            v[i] = max(height[i], v[i+1]);
        }
        temp = height[0];
        for (i=1;i<n-1;i++) {
            ans += (min(temp, v[i])-height[i] > 0 )*(min(temp, v[i])-height[i]);
            temp = max(temp, height[i]);
        }
        return ans;
    }
};


// Method 2
// Time complexity: O(n), Space complexity: O(1)
class Solution {
public:
    int trap(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                ++left;
            }
            else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};