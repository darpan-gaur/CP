/*
https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
*/

#include <iostream>

using namespace std;

// Recursive
int Recursive(int val[], int wt[], int n, int w) {
    // base case
    if (n == 0 || w == 0) {
        return 0;
    }
    // recursive calls
    if (wt[n-1] <= w) {
        return max(val[n-1] + Recursive(val, wt, n, w-wt[n-1]), Recursive(val, wt, n-1, w));
    }
    return Recursive(val, wt, n-1, w);
}

// Memoization
int Memoization(int val[], int wt[], int n, int w, int **dp) {
    // base case
    if (n == 0 || w == 0) {
        return 0;
    }
    // check if already calculated
    if (dp[n][w] != -1) {
        return dp[n][w];
    }
    // recursive calls
    if (wt[n-1] <= w) {
        return dp[n][w] = max(val[n-1] + Memoization(val, wt, n, w-wt[n-1], dp), Memoization(val, wt, n-1, w, dp));
    }
    return dp[n][w] = Memoization(val, wt, n-1, w, dp);
}

// Tabulation
int Tabulation(int val[], int wt[], int n, int w) {
    int dp[n+1][w+1];
    // base case
    for (int i=0;i<n+1;i++) dp[i][0] = 0;
    for (int i=0;i<w+1;i++) dp[0][i] = 0;
    // choice diagram
    for (int i=1;i<n+1;i++) {
        for (int j=1;j<w+1;j++) {
            if (wt[i-1] <= j) {
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int main() {
    int n, w;
    cin >> n >> w;
    int val[n], wt[n];
    for (int i=0;i<n;i++) cin >> val[i];
    for (int i=0;i<n;i++) cin >> wt[i];
    /*
    4 8
    1 4 5 7
    1 3 4 5
    Answer: 11
    */
    cout << "Recursive :- " << Recursive(val, wt, n, w) << endl;

    int **dp = new int*[n+1];
    for (int i=0;i<n+1;i++) {
        dp[i] = new int[w+1];
        for (int j=0;j<w+1;j++) {
            dp[i][j] = -1;
        }
    }
    cout << "Memoization :- " << Memoization(val, wt, n, w, dp) << endl;
    
    cout << "Tabulation :- " << Tabulation(val, wt, n, w) << endl;
    return 0;
}