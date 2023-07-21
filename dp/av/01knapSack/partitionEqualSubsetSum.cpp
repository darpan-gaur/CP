/*
https://leetcode.com/problems/partition-equal-subset-sum/

Also see this problem solution using bit-manipulation in dp folder
*/

#include <iostream>

using namespace std;

// recursive
// Time complexity - O(2^n)
// Space complexity - O(n)
bool subsetSumRecursive(int arr[], int n, int sum) {
    // base condition
    if (sum==0) return true;
    if (n==0) return false;

    // choice diagram
    if (arr[n-1] <= sum) {
        return subsetSumRecursive(arr, n-1, sum-arr[n-1]) || subsetSumRecursive(arr, n-1, sum);
    }
    
    return subsetSumRecursive(arr, n-1, sum);
}

// memoization
// dp -> int , but return type -> bool // keep this in mind 
// Time complexity - O(n*sum)
// Space complexity - O(n*sum)
bool subsetSumMemoization(int arr[], int n, int sum, int **dp) {
    // base condition
    if (sum==0) return true;
    if (n==0) return false;

    // choice diagram
    if (dp[n][sum] != -1) return dp[n][sum];
    if (arr[n-1] <= sum) {
        return dp[n][sum] = subsetSumMemoization(arr, n-1, sum-arr[n-1], dp) || subsetSumMemoization(arr, n-1, sum, dp);
    }
    
    return dp[n][sum] = subsetSumMemoization(arr, n-1, sum, dp);
}

// top-down
// Time complexity - O(n*sum)
// Space complexity - O(n*sum)
bool subsetSumTopDown(int arr[], int n, int sum) {
    int **dp = new int*[n+1];
    for (int i=0;i<n+1;i++) {
        dp[i] = new int[sum+1];
        for (int j=0;j<sum+1;j++) dp[i][j] = -1;
    }

    // base condition
    for (int i=0;i<n+1;i++) dp[i][0] = true;
    for (int i=1;i<sum+1;i++) dp[0][i] = false;

    // choice diagram
    for (int i=1;i<n+1;i++) {
        for (int j=1;j<sum+1;j++) {
            if (arr[i-1] <= j) {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

bool canPartition(int arr[], int n) {
    int sum = 0;
    for (int i=0;i<n;i++) sum += arr[i];
    if (sum%2 != 0) return false;
    cout << "recursive: " << subsetSumRecursive(arr, n, sum/2) << endl;
    int **dp = new int*[n+1];
    for (int i=0;i<n+1;i++) {
        dp[i] = new int[sum/2+1];
        for (int j=0;j<sum/2+1;j++) dp[i][j] = -1;
    }
    cout << "memoization: " << subsetSumMemoization(arr, n, sum/2, dp) << endl;

    cout << "top-down: " << subsetSumTopDown(arr, n, sum/2) << endl;
    // return subsetSumRecursive(arr, n, sum/2);
    // return subsetSumMemoization(arr, n, sum/2, dp);
    return subsetSumTopDown(arr, n, sum/2);
}

int main() {
    int n, sum=0;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    /*
    6
    8 7 6 12 4 5
    Ans - 1
    */

    cout << canPartition(arr, n) << endl;

    return 0;
}