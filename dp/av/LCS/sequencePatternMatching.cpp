/*
https://practice.geeksforgeeks.org/problems/check-for-subsequence4930/1
*/

#include <iostream>

using namespace std;

// recursive 
// Time :- O(n)
bool recursive(string &s1, string &s2, int n, int m) {
    // base condition
    if (n==0) return true;
    if (m==0) return false;

    // choice diagram
    if (s1[n-1] == s2[m-1]) {
        return recursive(s1, s2, n-1, m-1);
    } 
    return recursive(s1, s2, n, m-1);
}

// memoization
// memory limit exceeded
bool memoization(string &s1, string &s2, int n, int m, int **dp) {
    // base condition
    if (n==0) return true;
    if (m==0) return false;

    // check if already calculated
    if (dp[n][m] != -1) return dp[n][m];

    // choice diagram
    if (s1[n-1] == s2[m-1]) {
        return dp[n][m] = memoization(s1, s2, n-1, m-1, dp);
    } 
    return dp[n][m] = memoization(s1, s2, n, m-1, dp);
}

// top down
// memory limit exceeded
bool topDown(string &s1, string &s2, int n, int m) {
    // create dp array
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[m+1];
    }

    // initialization
    for (int i=0;i<=m;i++) {
        dp[0][i] = true;
    }
    for (int i=1;i<=n;i++) {
        dp[i][0] = false;
    }

    // choice diagram
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    return dp[n][m];
}

// two pointer
bool twoPointer(string &s1, string &s2, int n, int m) {
    int i=0, j=0;
    while (i<n && j<m) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }
    return i==n;
}

// using LCS 
// find LCS of s1 and s2, if LCS == s1 then return true else false

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    /*
    axy yadxcpy
    Ans - 1
    */

    cout << "recursive :- " << recursive(s1, s2, n, m) << endl;

    // memoization
    int **dp = new int*[n+1];
    for (int i=0; i<=n; i++) {
        dp[i] = new int[m+1];
        for (int j=0; j<=m; j++) {
            dp[i][j] = -1;
        }
    }
    cout << "memoization :- " << memoization(s1, s2, n, m, dp) << endl;
    
    // top down
    cout << "top down :- " << topDown(s1, s2, n, m) << endl;
    
    // two pointer
    cout << "two pointer :- " << twoPointer(s1, s2, n, m) << endl;
    return 0;
}