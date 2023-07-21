/*
https://leetcode.com/problems/target-sum/
*/

#include <iostream>
#include <vector>

using namespace std;

// Recursive
int recursive(vector<int>& arr, int n, int sum, int target) {
    // base case
    if (n == 0) {
        if (sum == target) {
            return 1;
        }
        return 0;
    }
    // recursive calls
    int count = 0;
    count += recursive(arr, n-1, sum+arr[n-1], target);
    count += recursive(arr, n-1, sum-arr[n-1], target);
    return count;
}

// Memoization
int memoization(vector<int>& arr, int n, int sum, int target, int total, vector<vector<int>>& dp) {
    // base case
    if (n == 0) {
        if (sum == target) {
            return 1;
        }
        return 0;
    }
    // check if already calculated
    if (dp[n][sum+total] != -1) {
        return dp[n][sum+total];
    }
    // recursive calls
    int count = 0;
    count += memoization(arr, n-1, sum+arr[n-1], target, total, dp);
    count += memoization(arr, n-1, sum-arr[n-1], target, total, dp);
    return dp[n][sum+total] = count;
}

// Tabulation
int tabulation(vector<int>& arr, int n, int target) {
    int total = 0;
    for (int i=0; i<n; i++) {
        total += arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(2*total+1, 0));
    // base case
    dp[0][total+arr[0]] = 1;
    dp[0][total-arr[0]] += 1;
    // recursive calls
    for (int i=1; i<n; i++) {
        for (int sum = -total; sum <= total; sum++) {
            if (dp[i-1][total+sum] > 0) {
                dp[i][total+sum+arr[i]] += dp[i-1][total+sum];
                dp[i][total+sum-arr[i]] += dp[i-1][total+sum];
            }
        }
    }
    return (abs(target)>total) ? 0:  dp[n-1][total+target];
}

int main() {
    int n,target;
    cin >> n >> target;
    vector<int> arr(n);
    int total = 0;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    /*
    5 3
    1 1 1 1 1
    Ans- 5
    */
    cout << recursive(arr, n, 0, target) << endl;

    vector<vector<int>> dp(n+1, vector<int>(2*total+1, -1));
    cout << memoization(arr, n, 0, target, total, dp) << endl;
    
    cout << tabulation(arr, n, target) << endl;
    return 0;
}