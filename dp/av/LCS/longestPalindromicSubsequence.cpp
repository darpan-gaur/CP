/*
https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
*/

#include <iostream>

using namespace std;

// recursive
int recursive(string s1, int a, int b) {
    // base case
    if (a == b) {
        return 1;
    }
    if (a > b) {
        return 0;
    }

    // choice diagram
    if (s1[a] == s1[b]) {
        return 2 + recursive(s1, a + 1, b - 1);
    } else {
        return max(recursive(s1, a + 1, b), recursive(s1, a, b - 1));
    }
}

// memoization
int memoization(string s1, int a, int b, int **dp) {
    // base case
    if (a == b) {
        return 1;
    }
    if (a > b) {
        return 0;
    }
    // check if already calculated
    if (dp[a][b] != -1) {
        return dp[a][b];
    }

    if (s1[a] == s1[b]) {
        dp[a][b] = 2 + memoization(s1, a + 1, b - 1, dp);
    } else {
        dp[a][b] = max(memoization(s1, a + 1, b, dp), memoization(s1, a, b - 1, dp));
    }

    return dp[a][b];
}

// top down
int topDown(string s1) {
    int n = s1.length();
    int **dp = new int*[n];
    for (int i = 0; i < n; i++) {
        dp[i] = new int[n];
    }

    // outer loop i=n-1 to 0, at end we'll get lps for all substrings starting from i
    // inner loop j =i +1 to n-1
    for (int i=n-1;i>=0;i--) {
        // base case
        dp[i][i] = 1;
        for (int j=i+1;j<n;j++) {
            // choice diagram
            if (s1[i] == s1[j]) {
                dp[i][j] = 2 + dp[i+1][j-1];
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    return dp[0][n - 1];
}

// using lcs
int lcs(string s1, string s2, int n, int m) {
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
    string s1;
    cin >> s1;
    
    cout << "recursive :- " << recursive(s1, 0, s1.length() - 1) << endl;
    
    // memoization
    int **dp = new int*[s1.length()];
    for (int i = 0; i < s1.length(); i++) {
        dp[i] = new int[s1.length()];
        for (int j = 0; j < s1.length(); j++) {
            dp[i][j] = -1;
        }
    }
    cout << "memoization :- " << memoization(s1, 0, s1.length() - 1, dp) << endl;
    
    // top down
    cout << "top down :- " << topDown(s1) << endl;

    // using lcs
    string s2 = s1;
    int i=0,j=s2.length()-1;
    while(i<j) {
        swap(s2[i++],s2[j--]);
    }
    cout << "using lcs :- " << lcs(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}