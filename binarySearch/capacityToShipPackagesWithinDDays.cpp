/*
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/

// Solution 1: Binary Search
// Time complexity: O(nlogn), Space complexity: O(1)
class Solution {
public:
    bool solve(int mid, int days, vector<int>& weights, int n) {
        int i,sum=0, tempDays = 1;
        for (i=0;i<n;i++) {
            if (sum + weights[i] <= mid) {
                sum += weights[i];
            }
            else {
                tempDays++;
                if (tempDays > days || weights[i] > mid) return false;
                sum = weights[i];
            }
        } 
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int a=0, b=0, i, n = weights.size(),ans=-1;
        for (i=0;i<n;i++) b+= weights[i];
        while (a<=b) {
            int mid = a + (b-a)/2;
            if (solve(mid, days, weights, n)) {
                ans = mid;
                b = mid-1;
            }
            else {
                a = mid+1;
            }
        }
        return ans;
    }
};

// Clean code
class Solution {
public:
    // Check whether the packages can be shipped in less than "days" days with
    // "c" capacity.
    bool feasible(vector<int>& weights, int c, int days) {
        int daysNeeded = 1, currentLoad = 0;
        for (int weight : weights) {
            currentLoad += weight;
            if (currentLoad > c) {
                daysNeeded++;
                currentLoad = weight;
            }
        }

        return daysNeeded <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int totalLoad = 0, maxLoad = 0;
        for (int weight : weights) {
            totalLoad += weight;
            maxLoad = max(maxLoad, weight);
        }

        int l = maxLoad, r = totalLoad;

        while (l < r) {
            int mid = (l + r) / 2;
            if (feasible(weights, mid, days)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
