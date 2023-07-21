/*
https://practice.geeksforgeeks.org/problems/form-a-palindrome2544/1
*/

#include <iostream>

using namespace std;

// recursive
int recursive(string &s, int i, int j) {
    // base condition
    if (i>=j) return 0;

    // choice diagram
    if (s[i] == s[j]) {
        return recursive(s, i+1, j-1);
    }
    return 1 + min(recursive(s, i+1, j), recursive(s, i, j-1));
}

// memoization
int memoization(string &s, int i, int j, int **dp) {
    // base condition
    if (i>=j) return 0;

    // check if already calculated
    if (dp[i][j] != -1) return dp[i][j];

    // choice diagram
    if (s[i] == s[j]) {
        return dp[i][j] = memoization(s, i+1, j-1, dp);
    }
    return dp[i][j] = 1 + min(memoization(s, i+1, j, dp), memoization(s, i, j-1, dp));
}

// top down
int topDown(string &s) {
    int n = s.length();
    int **dp = new int*[n];
    for (int i=0;i<n;i++) {
        dp[i] = new int[n];
    }

    for (int i=n-1;i>=0;i--) {
        // base condition
        dp[i][i] = 0;
        for (int j=i+1;j<n;j++) {
            // choice diagram
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}

// using LCS
int lcs(string &s) {
    string s1 = s;
    for (int i=0,j=s.length()-1;i<j;i++,j--) {
        swap(s1[i], s1[j]);
    }
    string s2 = s;
    int n = s1.length();
    int **dp = new int*[n+1];
    for (int i=0;i<=n;i++) {
        dp[i] = new int[n+1];
    }

    for (int i=0;i<=n;i++) {
        for (int j=0;j<=n;j++) {
            if (i==0 || j==0) {
                dp[i][j] = 0;
            } else if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return n - dp[n][n];
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    /*
    abacaba - 0;
    abcd - 3
    */

    cout << "recursive :- " << recursive(s, 0, n-1) << endl;

    // memoization
    int **dp = new int*[n];
    for (int i=0;i<n;i++) {
        dp[i] = new int[n];
        for (int j=0;j<n;j++) {
            dp[i][j] = -1;
        }
    }
    cout << "memoization :- " << memoization(s, 0, n-1, dp) << endl;
    
    // top down
    cout << "top down :- " << topDown(s) << endl;
    
    // using LCS
    cout << "using LCS :- " << lcs(s) << endl;
    return 0;
}