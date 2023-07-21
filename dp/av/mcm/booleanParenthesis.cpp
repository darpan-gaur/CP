/*
https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
*/

#include <iostream>

using namespace std;

// recursive
int recursive(string &s, int i, int j, int ch) {
    if (i > j) return 0;
    if (i == j) {
        return (s[i] == ch);
    }
    int ans = 0;
    for (int k = i + 1; k < j; k += 2) {
        int lt = recursive(s, i, k - 1, 'T');
        int lf = recursive(s, i, k - 1, 'F');
        int rt = recursive(s, k + 1, j, 'T');
        int rf = recursive(s, k + 1, j, 'F');
        if (s[k] == '&') {
            if (ch == 'T') ans += lt * rt;
            else ans += lt * rf + lf * rt + lf * rf;
        } else if (s[k] == '|') {
            if (ch == 'T') ans += lt * rt + lt * rf + lf * rt;
            else ans += lf * rf;
        } else {
            if (ch == 'T') ans += lt * rf + lf * rt;
            else ans += lt * rt + lf * rf;
        }
        ans = ans % 1003;  
    }
    return ans;
}

// memoization
int memoization(string &s, int i, int j, int cond, int ***dp) {
    if (i > j) return 0;
    if (i==j) {
        if (cond == 1) return (s[i] == 'T');
        else return (s[i] == 'F');
    }
    if (dp[i][j][cond] != -1) return dp[i][j][cond];
    int ans = 0;
    for (int k = i + 1; k < j; k += 2) {
        int lt = memoization(s, i, k - 1, 1, dp);
        int lf = memoization(s, i, k - 1, 0, dp);
        int rt = memoization(s, k + 1, j, 1, dp);
        int rf = memoization(s, k + 1, j, 0, dp);
        if (s[k] == '&') {
            if (cond == 1) ans += lt * rt;
            else ans += lt * rf + lf * rt + lf * rf;
        } else if (s[k] == '|') {
            if (cond == 1) ans += lt * rt + lt * rf + lf * rt;
            else ans += lf * rf;
        } else {
            if (cond == 1) ans += lt * rf + lf * rt;
            else ans += lt * rt + lf * rf;
        }
        ans = ans % 1003;
    }
    return dp[i][j][cond] = ans;
}

// tabulation 1
int tabulation1(string &s) {
    int n = s.length();
    int ***dp = new int**[n];
    for (int i = 0; i < n; i++) {
        dp[i] = new int*[n];
        for (int j = 0; j < n; j++) {
            dp[i][j] = new int[2];
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    for (int i = 0; i < n; i += 2) {
        if (s[i] == 'T') dp[i][i][1] = 1;
        else dp[i][i][0] = 1;
    }
    for (int i=n-1;i>=0;i-=2) {
        for (int j=i+2;j<n;j+=2) {
            for (int k=i+1;k<j;k+=2) {
                int lt = dp[i][k-1][1];
                int lf = dp[i][k-1][0];
                int rt = dp[k+1][j][1];
                int rf = dp[k+1][j][0];
                if (s[k] == '&') {
                    dp[i][j][1] += lt * rt;
                    dp[i][j][0] += lt * rf + lf * rt + lf * rf;
                } else if (s[k] == '|') {
                    dp[i][j][1] += lt * rt + lt * rf + lf * rt;
                    dp[i][j][0] += lf * rf;
                } else {
                    dp[i][j][1] += lt * rf + lf * rt;
                    dp[i][j][0] += lt * rt + lf * rf;
                }
                dp[i][j][1] = dp[i][j][1] % 1003;
                dp[i][j][0] = dp[i][j][0] % 1003;
            }
        }
    }
    return dp[0][n-1][1];
}

// tabulation 2
int tabulation2(string &s) {
    int n = s.length();
    int ***dp = new int**[n];
    for (int i = 0; i < n; i++) {
        dp[i] = new int*[n];
        for (int j = 0; j < n; j++) {
            dp[i][j] = new int[2];
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    for (int i = 0; i < n; i += 2) {
        if (s[i] == 'T') dp[i][i][1] = 1;
        else dp[i][i][0] = 1;
    }
    // write comments for below code
    for (int l = 2;l<n;l+=2) {  // l is length of substring, here 2 as we are considering only characters
        for (int i=0;i<n-l;i+=2) {  // i is starting index of substring
            int j = i + l;  // j is ending index of substring
            for (int k=i+1;k<j;k+=2) {
                int lt = dp[i][k-1][1];
                int lf = dp[i][k-1][0];
                int rt = dp[k+1][j][1];
                int rf = dp[k+1][j][0];
                if (s[k] == '&') {
                    dp[i][j][1] += lt * rt;
                    dp[i][j][0] += lt * rf + lf * rt + lf * rf;
                } else if (s[k] == '|') {
                    dp[i][j][1] += lt * rt + lt * rf + lf * rt;
                    dp[i][j][0] += lf * rf;
                } else {
                    dp[i][j][1] += lt * rf + lf * rt;
                    dp[i][j][0] += lt * rt + lf * rf;
                }
                dp[i][j][1] = dp[i][j][1] % 1003;
                dp[i][j][0] = dp[i][j][0] % 1003;
            }
        }
    }

    return dp[0][n-1][1];
}

int main() {
    string s;
    cin >> s;
    /*
    T|T&F^T :- 4
    T^F|F :- 2
    */
    cout << "recursive :- " << recursive(s, 0, s.length() - 1, 'T') << endl;
    
    // memoization
    int ***dp = new int**[s.length()];
    for (int i = 0; i < s.length(); i++) {
        dp[i] = new int*[s.length()];
        for (int j = 0; j < s.length(); j++) {
            dp[i][j] = new int[2];
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    cout << "memoization :- " << memoization(s, 0, s.length() - 1, 1, dp) << endl;
    
    // tabulation 1
    cout << "tabulation 1 :- " << tabulation1(s) << endl;

    // tabulation 2
    cout << "tabulation 2 :- " << tabulation2(s) << endl;
    return 0;
}