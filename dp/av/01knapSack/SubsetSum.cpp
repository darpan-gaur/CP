/*
https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

Time Complexity: O(N*sum)
Space Complexity: O(N*sum)
*/

#include <iostream>
#include <vector>

using namespace std;

// recursive
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

int subsetSumTopDown(int arr[], int n, int sum) {
    bool dp[n+1][sum+1];
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

int main() {
    int n, sum;
    cin >> n >> sum;    
    int arr[n];
    for (int i=0;i<n;i++) cin >> arr[i];
    /*
    6 9
    3 34 4 12 5 2
    Ans: 1
    */

    cout << subsetSumRecursive(arr, n, sum) << endl;

    int **dp = new int*[n+1];
    for (int i=0;i<=n;i++) {
        dp[i] = new int[sum+1];
        for (int j=0;j<=sum;j++) dp[i][j] = -1;
    }
    cout << subsetSumMemoization(arr, n, sum, dp) << endl;

    cout << subsetSumTopDown(arr, n, sum) << endl;
    return 0;
}