/*
https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/

#include <iostream>
#include <vector>

using namespace std;

// recursive
int knapsackRecursive(int wt[], int val[], int n, int w) {
    // base condition
    if (n==0 || w==0) return 0;

    // choice diagram
    if (wt[n-1] <= w) {
        return max(val[n-1] + knapsackRecursive(wt, val, n-1, w-wt[n-1]), knapsackRecursive(wt, val, n-1, w));
    }
    else {
        return knapsackRecursive(wt, val, n-1, w);
    }
}

// memoization
int knapsackMemoization(int wt[], int val[], int n, int w, vector<vector<int>> &dp) {
    // base condition
    if (n==0 || w==0) return 0;

    // choice diagram
    if (dp[n][w] != -1) return dp[n][w];
    if (wt[n-1] <= w) {
        return dp[n][w] = max(val[n-1] + knapsackMemoization(wt, val, n-1, w-wt[n-1], dp), knapsackMemoization(wt, val, n-1, w, dp));
    }
    else {
        return dp[n][w] = knapsackMemoization(wt, val, n-1, w, dp);
    }
}

// top-down
// Time complexity: O(n*w)
// Space complexity: O(n*w)
int knapsackTopDown(int wt[], int val[], int n, int w) {
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    // base condition
    for (int i=0;i<n+1;i++) dp[i][0] = 0;
    for (int i=0;i<w+1;i++) dp[0][i] = 0;

    // choice diagram
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<w+1; j++) {
            if (wt[i-1] <= j) {
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][w];
}


int main() {
    int n,w;
    cin>>n>>w;
    int wt[n], val[n];
    cout << "Enter values: ";
    for (int i=0; i<n; i++) cin>>val[i];
    cout << "Enter weights: ";
    for (int i=0; i<n; i++) cin>>wt[i];
    /*
    3 4
    1 2 3
    4 5 1
    Ans = 3
    */
    cout << knapsackRecursive(wt, val, n, w) << endl;

    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    cout << knapsackMemoization(wt, val, n, w, dp) << endl;

    cout << knapsackTopDown(wt, val, n, w) << endl;

    return 0;
}