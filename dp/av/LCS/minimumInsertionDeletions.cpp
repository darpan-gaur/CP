/*
https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
*/

#include <iostream>

using namespace std;

// minimum number of deletions and insertions to convert string a to string b

// recursive
int recursive(string &s1, string &s2, int n, int m) {
    // base case
    if (n==0 || m==0) {
        return n+m;
    }

    // choice diagram
    if (s1[n-1] == s2[m-1]) {
        return recursive(s1, s2, n-1, m-1);
    } else {
        int Insert = 1 + recursive(s1, s2, n, m-1);
        int Delete = 1 + recursive(s1, s2, n-1, m);
        return min(Insert, Delete);
    }
}

// memoization
int memoization(string &s1, string &s2, int n, int m, int **dp) {
    // base case
    if (n==0 || m==0) {
        return n+m;
    }

    // check if already calculated
    if (dp[n][m] != -1) {
        return dp[n][m];
    }

    // choice diagram
    if (s1[n-1] == s2[m-1]) {
        return dp[n][m] = memoization(s1, s2, n-1, m-1, dp);
    } else {
        int Insert = 1 + memoization(s1, s2, n, m-1, dp);
        int Delete = 1 + memoization(s1, s2, n-1, m, dp);
        return dp[n][m] = min(Insert, Delete);
    }
}

// top down
int topDown(string &s1, string &s2, int n, int m) {
    // create dp array
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[m+1];
    }

    // base case
    for(int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for(int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    // choice diagram
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // if match
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1]; 
            } else {
                int Insert = 1 + dp[i][j-1];
                int Delete = 1 + dp[i-1][j];
                dp[i][j] = min(Insert, Delete);
            }
        } 
    }

    return dp[n][m];
}

// using lcs
int lcs(string &s1, string &s2, int n, int m) {
    // create dp array
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[m+1];
    }

    // base case
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for(int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }

    // choice diagram
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // if match
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1]; 
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        } 
    }

    return dp[n][m];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    /*
    sea eat
    Ans 2
    */

    cout << "recursive :- " << recursive(s1, s2, n, m) << endl;

    // memoization
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[m+1];
        for(int j = 0; j <= m; j++) {
            dp[i][j] = -1;
        }
    }
    cout << "memoization :- " << memoization(s1, s2, n, m, dp) << endl;

    // top down
    cout << "top down :- " << topDown(s1, s2, n, m) << endl;

    // using lcs
    cout << "using lcs :- " << n + m - 2 * lcs(s1, s2, n, m) << endl;
    return 0;
}