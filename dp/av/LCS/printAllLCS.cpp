/*
https://practice.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

// backtracking
void getAllLcs(string s1, string s2, int i1, int i2, int lcs, string s, set<string> &ans) {
    if(lcs==0) {
        ans.insert(s);
        return;
    }
    if (i1==s1.size() || i2==s2.size()) return;
    for (int i=i1; i<s1.size(); i++) {
        for (int j=i2; j<s2.size(); j++) {
            if (s1[i]==s2[j]) {
                s.push_back(s1[i]);
                getAllLcs(s1, s2, i+1, j+1, lcs-1, s, ans);
                s.pop_back();
            }
        }
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    int **dp;
    dp = new int*[n+1];
    for(int i=0; i<=n; i++) dp[i] = new int[m+1];
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int i=0; i<=m; i++) dp[0][i] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    int lcs = dp[n][m];
    set<string> ans;
    string temp = "";
    getAllLcs(s1, s2, 0, 0, lcs, temp, ans);
    for(auto i: ans) cout << i << endl;
    return 0;
}