/*
https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
*/

#include <iostream>
#include <climits> // for INT_MAX

using namespace std;

// recursive
int recursive(int arr[], int i, int j) {
    // base case
    if (i >= j) {
        return 0;
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int temp = recursive(arr, i, k) + recursive(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, temp);
    }
    return ans;
}

// memoization
int memoization(int arr[], int i, int j, int **dp) {
    // base case
    if (i >= j) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int temp = memoization(arr, i, k, dp) + memoization(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}

// tabulation
int tabulation(int arr[], int n) {
    int dp[n][n];
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // version 1
    // for (int i=n-1; i>=1; i--) {
    //     for (int j=i+1; j<n; j++) {
    //         int ans = INT_MAX;
    //         for (int k=i; k<j; k++) {
    //             ans = min(ans, dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
    //         }
    //         dp[i][j] = ans;
    //     }
    // }

    // version 2
    for (int len=1; len<n; len++) {
        for (int i=1; i+len<n; i++) {
            int j = i+len;
            int ans = INT_MAX;
            for (int k=i; k<j; k++) {
                ans = min(ans, dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
            }
            dp[i][j] = ans;
        }
    }

    return dp[1][n - 1];
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0 ; i < n; i++) {
        cin >> arr[i];
    }
    /*
    5
    40 20 30 10 30
    Ans - 26000
    */

    cout << "recursive :- " << recursive(arr, 1, n - 1) << endl;

    // memoization
    int **dp = new int*[n];
    for (int i = 0; i < n; i++) {
        dp[i] = new int[n];
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    cout << "memoization :- " << memoization(arr, 1, n - 1, dp) << endl;

    // tabulation
    cout << "tabulation :- " << tabulation(arr, n) << endl;
    return 0;
}