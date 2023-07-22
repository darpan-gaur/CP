#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;

const int mod = 1e9+7;

vector<vector<int>> a(31);

void preComp() {
    for (int i=1;i<=1000;i++) {
        int x=i,sum=0;
        while (x) {
            sum+=(x%10);
            x /= 10;
        }
        if (sum<=30 && sum) a[sum].push_back(i); 
    }
}

vector<vector<int>> dp(101, vector<int> (1001));
int memo(vector<int>& s, int i, int prev){
    if (i==s.size()) return 1;
    
    if (dp[i][prev]!=-1) return dp[i][prev];

    int ans=0;
    int idx = upper_bound(a[s[i]].begin(), a[s[i]].end(), prev)-a[s[i]].begin();
    for (int j=idx;j<a[s[i]].size();j++) {
        ans = (ans + memo(s, i+1, a[s[i]][j]))%mod;
    }
    return dp[i][prev]=ans;
}

void solve(){
    int n,i,j;
    cin >> n;
    vector<int> s(n);
    for (i=0;i<n;i++) cin >> s[i];
    for (i=0;i<=100;i++) {
        for (j=0;j<=1000;j++) dp[i][j] = -1;
    }
    cout << memo(s, 0, 0) << "\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    preComp();
    while (t--){
        solve();
    }
    return 0;
}

/*
Finding Arrays
Given an array S of N elements. We need to find the count of distinct
arrays A of N elements that exists such that:
    - A[i] < A[i+1] for all 1<=i<N
    - Sum of digits of A[i] is equal to S[i] for all 1<=i<=N
    - 1<=A[i]<=1e3
Since the count can be very large. Output the answer modulo 1e9+7.
Input Format
    - T :- Testcases
    - N :- Size of array
    - N spaced integers, S[i]
Output Format
    - Print the answer modulo 1e9+7

Constraints
    - 1<=T<=5
    - 1<=N<=100
    - 1<=S[i]<=30

Sample Input 1
4
3
10 15 16
6
3 6 10 14 12 17
10
3 9 9 3 11 7 14 15 11 17
9
2 7 3 5 9 13 9 14 11
Sample Output 1
101776
142727553
303300404
19829619

Sample Input 2
4
3
8 7 12
10
7 6 7 8 11 13 15 13 9 16
7
9 3 5 11 12 9 14
10
2 6 8 4 5 8 7 12 14 1
Sample Output 2
30242
629563671
288757998
868587712
*/