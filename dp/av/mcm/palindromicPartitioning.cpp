/*
https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
*/

#include <iostream>
#include <climits>  // INT_MAX

using namespace std;

// recursive
int recursive(string &s, int i, int j) { 
    // base case
    if (i >= j) return 0;

    // check for palindrome
    bool isPalindrome = true;
    for (int k = i; k <= (i + j) / 2; k++) {
        if (s[k] != s[j - k + i]) {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome) return 0;

    // recursive case
    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int temp = recursive(s, i, k) + recursive(s, k + 1, j) + 1;
        ans = min(ans, temp);
    }
    return ans;
}

// memoization
// TLE on gfg
int memoization(string &s, int i, int j, int **dp) {
    // base case
    if (i >= j) return 0;

    // check if already calculated
    if (dp[i][j] != -1) return dp[i][j];

    // check for palindrome
    bool isPalindrome = true;
    for (int k = i; k <= (i + j) / 2; k++) {
        if (s[k] != s[j - k + i]) {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome) return dp[i][j] = 0;

    // recursive case
    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int temp = memoization(s, i, k, dp) + memoization(s, k + 1, j, dp) + 1;
        ans = min(ans, temp);
    }
    dp[i][j] = ans;
    return ans;
}

// memoization + optimization
// passed on gfg
int memoization2(string &s, int i, int j, int **dp) {
    // base case
    if (i >= j) return 0;

    // check if already calculated
    if (dp[i][j] != -1) return dp[i][j];

    // check for palindrome
    bool isPalindrome = true;
    for (int k = i; k <= (i + j) / 2; k++) {
        if (s[k] != s[j - k + i]) {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome) return dp[i][j] = 0;

    // recursive case
    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int left, right;
        if (dp[i][k] != -1) left = dp[i][k];
        else left = memoization2(s, i, k, dp);
        if (dp[k + 1][j] != -1) right = dp[k + 1][j];
        else right = memoization2(s, k + 1, j, dp);
        int temp = left + right + 1;
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}

// tabulation - bottom up
// Time :- O(n^3), Space :- O(n^2)
int tabulation(string &s) {
    int n = s.length();
    int **dp = new int *[n];
    for (int i = 0; i < n; i++) {
        dp[i] = new int[n];
        dp[i][i] = 0;
    }

    // version 1
    // for (int l = 2; l <= n; l++) {
    //     for (int i = 0; i <= n - l; i++) {
    //         int j = i + l - 1;
    //         bool isPalindrome = true;
    //         for (int k = i; k <= (i + j) / 2; k++) {
    //             if (s[k] != s[j - k + i]) {
    //                 isPalindrome = false;
    //                 break;
    //             }
    //         }
    //         if (isPalindrome) dp[i][j] = 0;
    //         else {
    //             int ans = INT_MAX;
    //             for (int k = i; k < j; k++) {
    //                 int temp = dp[i][k] + dp[k + 1][j] + 1;
    //                 ans = min(ans, temp);
    //             }
    //             dp[i][j] = ans;
    //         }
    //     }
    // }

    // version 2
    for (int i=n-2;i>=0;i--){
        for (int j=i+1;j<n;j++){
            bool isPalindrome = true;
            for (int k=i;k<=(i+j)/2;k++){
                if (s[k] != s[j-k+i]){
                    isPalindrome = false;
                    break;
                }
            }
            if (isPalindrome) dp[i][j] = 0;
            else {
                int ans = INT_MAX;
                for (int k=i;k<j;k++){
                    int temp = dp[i][k] + dp[k+1][j] + 1;
                    ans = min(ans, temp);
                }
                dp[i][j] = ans;
            }
        }
    }
    return dp[0][n - 1];
}

// O(n^2) solution
void chkPal(string &s, bool **pal) {
    // size
    int n = s.length();

    // for single characters
    for (int i = 0; i < n; i++) {
        pal[i][i] = true;
    }

    // for two characters
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) pal[i][i + 1] = true;
        else pal[i][i + 1] = false;
    }

    // for more than two characters
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            if (s[i] == s[j] && pal[i + 1][j - 1]) pal[i][j] = true;
            else pal[i][j] = false;
        }
    }
}

int minPart(string &s) {
    // size
    int n = s.length();

    // check for palindrome
    bool **pal = new bool *[n];
    for (int i = 0; i < n; i++) {
        pal[i] = new bool[n];
    }
    chkPal(s, pal);

    // dp
    int *dp = new int[n];
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        // if string from 0 to i is palindrome, then no partition required
        if (pal[0][i]) dp[i] = 0;
        // else check for all partitions
        else {
            int ans = INT_MAX;
            // if string from j+1 to i is palindrome, then check for partition
            for (int j = 0; j < i; j++) {
                if (pal[j + 1][i] && ans > dp[j] + 1) ans = dp[j] + 1;
            }
            dp[i] = ans;
        }
    }
    return dp[n - 1];
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    /*
    ababbbabbababa - 3
    aaabba - 1
    */

    cout << "recursive :- " << recursive(s, 0, n - 1) << endl;

    // memoization
    int **dp = new int *[n];
    for (int i = 0; i < n; i++) {
        dp[i] = new int[n];
        for (int j = 0; j < n; j++) dp[i][j] = -1;
    }
    // cout << "memoization :- " << memoization(s, 0, n - 1, dp) << endl;

    // memoization + optimization
    cout << "memoization + optimization :- " << memoization2(s, 0, n - 1, dp) << endl;
    
    // tabulation
    cout << "tabulation :- " << tabulation(s) << endl;

    // O(n^2) solution
    cout << "O(n^2) solution :- " << minPart(s) << endl;
    return 0;
}