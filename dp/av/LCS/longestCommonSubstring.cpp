/*
https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
*/

#include <iostream>

using namespace std;

// recursive
int recursive(string s1, string s2, int n, int m, int count) {
    // base case
    if(n == 0 || m == 0) {
        return count;
    }

    if(s1[n-1] == s2[m-1]) {
        count = recursive(s1, s2, n-1, m-1, count+1);
    }
    return max(count, max(recursive(s1, s2, n-1, m, 0), recursive(s1, s2, n, m-1, 0)));
}

// memoization
int memoization(string &s1, string &s2, int n, int m, int **dp) {
    // base case
    if(n == 0 || m == 0) {
        return 0;
    }
    // check if already calculated
    if(dp[n][m] != -1) {
        return dp[n][m];
    }
    // recursive case
    if(s1[n-1] == s2[m-1]) {
        dp[n][m] = 1 + memoization(s1, s2, n-1, m-1, dp);
    } else {
        dp[n][m] = 0;
    }
    memoization(s1, s2, n-1, m, dp);
    memoization(s1, s2, n, m-1, dp);
    return dp[n][m];
}

// top down
int topDown(string &s1, string &s2, int n, int m) {
    int **dp = new int*[n+1];
    for(int i=0; i<=n; i++) {
        dp[i] = new int[m+1];
        for(int j=0; j<=m; j++) {
            dp[i][j] = 0;
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}

int main() {
    int n,m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    /*
    6 6
    abcdgh
    acdghr
    */

    cout << "recursive :- " << recursive(s1, s2, n, m, 0) << endl;

    // memoization
    int **dp = new int*[n+1];
    for(int i=0; i<=n; i++) {
        dp[i] = new int[m+1];
        for(int j=0; j<=m; j++) {
            dp[i][j] = -1;
        }
    }
    int ans = memoization(s1, s2, n, m, dp);
    // find max in dp
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << "memoization :- " << ans << endl;
    // free memory
    for(int i=0; i<=n; i++) {
        delete [] dp[i];
    }
    
    return 0;
}