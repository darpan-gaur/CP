/*
https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

// slight change including 0 in the array
// subset sum ->  just change || to + didn't work
*/

#include <iostream>

using namespace std;

int mod = 1e9+7;

// recursive
int recursive(int arr[], int n, int sum) {
    // base condition
    if (n==0) {
        return (sum==0);
    }

    // choice diagram
    if (arr[n-1] <= sum) {
        return (recursive(arr, n-1, sum-arr[n-1]) + recursive(arr, n-1, sum)) % mod;
    }

    return recursive(arr, n-1, sum) % mod;
}

// memoization
int memoization(int arr[], int n, int sum, int **dp) {
    // base condition
    if (n==0) {
        return (sum==0);
    }

    // choice diagram
    if (dp[n][sum] != -1) return dp[n][sum];
    if (arr[n-1] <= sum) {
        return dp[n][sum] = (memoization(arr, n-1, sum-arr[n-1], dp) + memoization(arr, n-1, sum, dp)) % mod;
    }

    return dp[n][sum] = memoization(arr, n-1, sum, dp) % mod;
}

// top-down
int topDown(int arr[], int n, int sum) {
    int dp[n+1][sum+1];
    for (int i=0;i<sum+1;i++) dp[0][i] = 0;
    for (int i=0;i<n+1;i++) dp[i][0] = 1;

    for (int i=1;i<n+1;i++) {
        for (int j=0;j<sum+1;j++) {
            if (arr[i-1] <= j) {
                dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]) % mod;
            } else {
                dp[i][j] = dp[i-1][j] % mod;
            }
        }
    }
    // printing dp array
    // cout << endl;
    // for (int i=0;i<n+1;i++) {
    //     for (int j=0;j<sum+1;j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[n][sum];
}

int main() {
    int n, sum;
    cin >> n >> sum;    
    int arr[n];
    for (int i=0;i<n;i++) cin >> arr[i];
    /*
    10 31
    9 7 0 3 9 8 6 5 7 6
    Ans - 37
    */

    cout << "recursive: " << recursive(arr, n, sum) << endl;

    int **dp = new int*[n+1];
    for (int i=0;i<n+1;i++) {
        dp[i] = new int[sum+1];
        for (int j=0;j<sum+1;j++) dp[i][j] = -1;
    }
    cout << "memoization: " << memoization(arr, n, sum, dp) << endl;

    cout << "top-down: " << topDown(arr, n, sum) << endl;

    return 0;
}