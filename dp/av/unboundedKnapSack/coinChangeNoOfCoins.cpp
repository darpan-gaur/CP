/*
https://practice.geeksforgeeks.org/problems/number-of-coins1824/1
*/

#include <iostream>
#include <climits>  // INT_MAX

using namespace std;

// recursive
int recursive(int coins[], int n, int amount) {
    // base case
    if (amount == 0) {
        return 0;
    }
    if (n == 0) {
        return INT_MAX-1;
    }
    // recursive calls
    if (coins[n-1] <= amount) {
        return min(1+recursive(coins, n, amount-coins[n-1]), recursive(coins, n-1, amount));
    }
    return recursive(coins, n-1, amount);
}

// memoization
int memoization(int coins[], int n, int amount, int **dp) {
    // base case
    if (amount == 0) {
        return 0;
    }
    if (n == 0) {
        return INT_MAX-1;
    }
    // check if already calculated
    if (dp[n][amount] != -1) {
        return dp[n][amount];
    }
    // recursive calls
    if (coins[n-1] <= amount) {
        return dp[n][amount] = min(1+memoization(coins, n, amount-coins[n-1], dp), memoization(coins, n-1, amount, dp));
    }
    return dp[n][amount] = memoization(coins, n-1, amount, dp);
}

// Top Down
int topDown(int coins[], int n, int amount) {
    // initialization
    int dp[n+1][amount+1];
    for (int i=0; i<=n; i++) {
        dp[i][0] = 0;
    }
    for (int j=1; j<=amount; j++) {
        dp[0][j] = INT_MAX-1;
    }
    // choice diagram
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=amount; j++) {
            if (coins[i-1] <= j) {
                dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][amount];
}

// 1D array
int oneD(int coins[], int n, int amount) {
    // initialization
    int dp[amount+1];
    for (int j=1; j<=amount; j++) {
        dp[j] = INT_MAX-1;
    }
    dp[0] = 0;
    // choice diagram
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=amount; j++) {
            if (coins[i-1] <= j) {
                dp[j] = min(1+dp[j-coins[i-1]], dp[j]);
            }
        }
    }
    return dp[amount];
}

int main() {
    int n, amount;
    cin >> n >> amount;
    int coins[n];
    for (int i=0; i<n; i++) {
        cin >> coins[i];
    }
    /*
    3 30
    25 10 5
    Answer: 2
    */

    // check case if answer is not possible
    cout << "recursive :- " << recursive(coins, n, amount) << endl;

    // memoization
    int **dp = new int*[n+1];
    for (int i=0; i<=n; i++) {
        dp[i] = new int[amount+1];
        for (int j=0; j<=amount; j++) {
            dp[i][j] = -1;
        }
    }
    cout << "memoization :- " << memoization(coins, n, amount, dp) << endl;

    // top down
    cout << "top down :- " << topDown(coins, n, amount) << endl;

    // 1D array
    cout << "1D array :- " << oneD(coins, n, amount) << endl;
    return 0;
}