/*
https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
*/

#include <iostream>

using namespace std;

// recursion
int recursive(string s, int n, int m) {
    // base condition
    if(n == 0 || m == 0) {
        return 0;
    }

    // choice diagram
    if (s[n-1] == s[m-1] && n != m) {
        return 1 + recursive(s, n-1, m-1);
    } else {
        return max(recursive(s, n-1, m), recursive(s, n, m-1));
    }
}

// memoization
// pass string as reference, to avoid tle
int memoization(string s, int n, int m, int **dp) {
    // base condition
    if(n == 0 || m == 0) {
        return 0;
    }

    // check if already calculated
    if(dp[n][m] != -1) {
        return dp[n][m];
    }

    // choice diagram
    if (s[n-1] == s[m-1] && n != m) {
        return dp[n][m] = 1 + memoization(s, n-1, m-1, dp);
    } else {
        return dp[n][m] = max(memoization(s, n-1, m, dp), memoization(s, n, m-1, dp));
    }
}

// top down
int topDown(string s, int n, int m) {
    // create dp array
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[m+1];
    }

    // initialization
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for(int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    // choice diagram
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // if same character and not same index
            if(s[i-1] == s[j-1] && i != j) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else { // if not same character
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // return answer
    return dp[n][m];
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    /*
    axxzxy
    Ans = 2
    */

    cout << "recursive :- " << recursive(s, n, n) << endl;

    // memoization
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[n+1];
        for(int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
    cout << "memoization :- " << memoization(s, n, n, dp) << endl;

    cout << "top down :- " << topDown(s, n, n) << endl;
    return 0;
}