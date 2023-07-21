/*
https://leetcode.com/problems/shortest-common-supersequence/
*/

#include <iostream>
#include <vector>

using namespace std;

// using lcs
int memoization(string s1, string s2, int n, int m, int **dp) {
    // base case
    if(n == 0 || m == 0) {
        return 0;
    }

    // check if already calculated
    if(dp[n][m] != -1) {
        return dp[n][m];
    }

    // choice diagram
    if(s1[n-1] == s2[m-1]) {
        return dp[n][m] = 1 + memoization(s1, s2, n-1, m-1, dp);
    } else {
        return dp[n][m] = max(memoization(s1, s2, n-1, m, dp), memoization(s1, s2, n, m-1, dp));
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();
    /*
    abac cab
    Ans :- cabac
    */

    // memoization
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[m+1];
        for(int j = 0; j <= m; j++) {
            dp[i][j] = -1;
        }
    }
    int lcs = memoization(s1, s2, n, m, dp);
    string ans = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            ans += s1[i-1];
            i--;
            j--;
        } else {
            if(dp[i-1][j] > dp[i][j-1]) {
                ans += s1[i-1];
                i--;
            } else {
                ans += s2[j-1];
                j--;
            }
        }
    }
    while (i > 0) {
        ans += s1[i-1];
        i--;
    }
    while (j > 0) {
        ans += s2[j-1];
        j--;
    }
    i=0,j=ans.length()-1;
    while(i<j){
        swap(ans[i++],ans[j--]);
    }
    cout << ans << endl;
    return 0;
}