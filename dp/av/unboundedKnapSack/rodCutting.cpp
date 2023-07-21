/*
https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
*/

#include <iostream>

using namespace std;

// Recursive
int recursive(int price[], int n, int len) {
    // base case
    if (n == 0 || len == 0) {
        return 0;
    }
    // recursive calls
    if (n <= len) {
        return max(price[n-1] + recursive(price, n, len-n), recursive(price, n-1, len));
    }
    return recursive(price, n-1, len);
}

// Memoization
int memoization(int price[], int n, int len, int **dp) {
    // base case
    if (n == 0 || len == 0) {
        return 0;
    }
    // check if already calculated
    if (dp[n][len] != -1) {
        return dp[n][len];
    }
    // recursive calls
    if (n <= len) {
        return dp[n][len] = max(price[n-1] + memoization(price, n, len-n, dp), memoization(price, n-1, len, dp));
    }
    return dp[n][len] = memoization(price, n-1, len, dp);
}

// Top Down
int topDown(int price[], int n, int len) {
    // base case
    int dp[n+1][len+1];
    for (int i=0;i<n+1;i++) {
        dp[i][0] = 0;
    }
    for (int j=0;j<len+1;j++) {
        dp[0][j] = 0;
    }
    // recursive calls
    for (int i=1;i<n+1;i++) {
        for (int j=1;j<len+1;j++) {
            if (i <= j) {
                dp[i][j] = max(price[i-1] + dp[i][j-i], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][len];
}

int main() {
    int n;
    cin >> n;
    int price[n];
    for (int i=0;i<n;i++) {
        cin >> price[i];
    }
    /*
    8
    1 5 8 9 10 17 17 20
    Answer: 22
    */
    int len = n;
    cout << "recursive :- " << recursive(price, n, len) << endl;

    int **dp = new int*[n+1];
    for (int i=0;i<n+1;i++) {
        dp[i] = new int[len+1];
        for (int j=0;j<len+1;j++) {
            dp[i][j] = -1;
        }
    }
    cout << "memoization :- " << memoization(price, n, len, dp) << endl;
    
    cout << "topDown :- " << topDown(price, n, len) << endl;
    return 0;
}