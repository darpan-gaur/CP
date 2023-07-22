#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;

int mem(vector<int>& A, vector<int> &B, int i, int j, int maxim, int minim, vector<vector<int>>&dp)
{
    if (i >= A.size() && j >= B.size())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int take_a = -1e8, take_b = -1e8;
    if (i < A.size())
        take_a = max(A[i],maxim) - min(A[i],minim) + mem(A,B,i+1,j,max(A[i],maxim),min(A[i],minim),dp);

    if (j < B.size())
        take_b = max(B[j],maxim) - min(B[j],minim) + mem(A,B,i,j+1,max(B[j],maxim),min(B[j],minim),dp);
        
    dp[i][j] = max(take_a, take_b);  
    return dp[i][j];
}

int ite(vector<int>& a, vector<int>& b, int n, int m) {
    vector<int> maxa(n), maxb(m), mina(n), minb(m);
    maxa[0]=mina[0] = a[0];
    for (int i=1;i<n;i++) {
        maxa[i] = max(maxa[i-1], a[i]);
        mina[i] = min(mina[i-1], a[i]);
    }
    maxb[0] = minb[0] = b[0];
    for (int i=1;i<m;i++) {
        maxb[i] = max(maxb[i-1], b[i]);
        minb[i] = min(minb[i-1], b[i]);
    }
    vector<vector<int>> dp(n+1, vector<int> (m+1));
    for (int i=0;i<=n;i++) {
        for (int j=i?0:1;j<=m;j++) {
            if (i) dp[i][j] = dp[i-1][j];
            if (j) dp[i][j] = max(dp[i][j], dp[i][j-1]);
            dp[i][j] += max(i?maxa[i-1]:0, j?maxb[j-1]:0) - min(i?mina[i-1]:INT_MAX, j?minb[j-1]:INT_MAX);
        } 
    }
    return dp[n][m];
}

void solve(){
    ll n,m,i,j;
    cin >> n;
    vector<int> a(n);
    for (i=0;i<n;i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (i=0;i<m;i++) cin >> b[i];
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    cout << mem(a, b, 0, 0, -1e8, 1e8, dp) << "\n";
    cout << ite(a, b, n , m)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}

/*
Hybrid Maximum
A hybrid sequence is a sequence that can be divided into two disjoint subsequences. 
Every subsequence is an array.
Given two arrays, A and B, of sizes N and M, respectively. You are also given a hybrid sequence S.
The expression sigma(i=1)^(i=n+m) max(s1, s2, ..., si) - sigma(i=1)^(i=n+m) min(s1, s2, ..., si) 
calculates the differnece between the sum of the maximum values and the sum of the 
minimum values of the hybrid sequence S.
Find the maximum value of the expression for all possible hybrid sequences.

Constraints:
- 1 <= T <= 1000
- 1 <= N, M <= 1000
- 1 <= Ai, Bi <= 10^6
- Sum of N x M over all test cases does not exceed 10^7

Sample Input:
1
3
1 2 3
2
4 1

Sample Output: 12
*/