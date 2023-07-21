/*
https://leetcode.com/problems/coin-change-ii/
*/

#include <iostream>
#include <vector>

using namespace std;

// recursive
int recursive(int amount, vector<int>& coins, int n) {
    // base case
    if (amount == 0) return 1;
    if (n == 0) return 0;

    if (amount >= coins[n-1]) {
        return recursive(amount-coins[n-1], coins, n) + recursive(amount, coins, n-1);
    }
    return recursive(amount, coins, n-1);
}

// memoization
int memoization(int amount, vector<int>& coins, int n, int **dp) {
    // base case
    if (amount == 0) return 1;
    if (n == 0) return 0;

    // check if already calculated
    if (dp[n][amount] != -1) {
        return dp[n][amount];
    }

    if (amount >= coins[n-1]) {
        return dp[n][amount] = memoization(amount-coins[n-1], coins, n, dp) + memoization(amount, coins, n-1, dp);
    }
    return dp[n][amount] = memoization(amount, coins, n-1, dp);
}

// top down
int topDown(int amount, vector<int>& coins, int n) {
    // base case
    int dp[n+1][amount+1];
    for (int i=0;i<n+1;i++) {
        dp[i][0] = 1;
    }
    for (int j=1;j<amount+1;j++) {
        dp[0][j] = 0;
    }

    // recursive calls
    for (int i=1;i<n+1;i++) {
        for (int j=1;j<amount+1;j++) {
            if (j >= coins[i-1]) {
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][amount];
}

// 1-d dp
int coinchange(int amount, vector<int>& coins) {
    int n = coins.size();
    int dp[amount+1];
    dp[0] = 1;
    for (int i=1;i<amount+1;i++) {
        dp[i] = 0;
    }

    for (int i=0;i<n;i++) {
        for (int j=1;j<amount+1;j++) {
            if (j >= coins[i]) {
                dp[j] += dp[j-coins[i]];
            }
        }
    }

    return dp[amount];
}

int main() {
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i=0;i<n;i++) {
        cin >> coins[i];
    }
    /*
    3 5
    1 2 5
    Answer: 4
    */

    cout << "recursive :- " << recursive(amount, coins, n) << endl;

    int **dp = new int*[n+1];
    for (int i=0;i<n+1;i++) {
        dp[i] = new int[amount+1];
        for (int j=0;j<amount+1;j++) {
            dp[i][j] = -1;
        }
    }
    cout << "memoization :- " << memoization(amount, coins, n, dp) << endl;
    
    cout << "top down :- " << topDown(amount, coins, n) << endl;

    cout << "1-d dp :- " << coinchange(amount, coins) << endl;
    return 0;
}