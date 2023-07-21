#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;

const int mod = 1e9 + 7;

// recursive
vector<vector<int>> a(12);
// int recursive(vector<int>& s, int n, int bound) {
// 	if (n==0) return 1;

// 	int ans = 0;
// 	for (int i=0;i<a[s[n-1]].size();i++) {
// 		if (a[s[n-1]][i]<bound) {

// 			ans = (ans + recursive(s, n-1, a[s[n-1]][i])) % mod;
// 		}
// 	}
// 	return ans;
// }

// memoization
vector<vector<int>> dp(101, vector<int> (1002, -1));
int memoization(vector<int>& s, int n, int bound) {
    if (n==0) return 1;

    if (dp[n][bound]!=-1) return dp[n][bound];

    int ans = 0;
    for (int i=0;i<a[s[n-1]].size();i++) {
        if (a[s[n-1]][i]<bound) {
            ans = (ans + memoization(s, n-1, a[s[n-1]][i])) % mod;
        }
    }
    return dp[n][bound] = ans;
}

void solve(){
    int n,i,temp,dsum;
    cin >> n;
    vector<int> s(n);
    for (i=0;i<n;i++) {
    	cin >> temp;
    	dsum=0;
    	while (temp) {
    		dsum+=temp;
    		temp = temp/10;
    	}
    	s[i] = dsum;
    }
    // for (auto x:s) cout << x << " ";
    // cout << "\n";
    for (i=1;i<=1000;i++) {
    	dsum = 0;
    	temp = i;
    	while (temp) {
    		dsum += temp%10;
    		temp = temp/10;
    	}
    	// cout << dsum << " " << temp << "\n";
    	if (dsum < 12) a[dsum].push_back(i);
    } 
    // for (auto u:a) {
    // 	for (auto v:u) cout << v << " ";
    // 	cout << "\n";
    // }
    // cout << recursive(s, n, 10000) << "\n";
    for (i=0;i<=n;i++) {
        for (int j=0;j<=1001;j++) dp[i][j] = -1;
    }
    cout << memoization(s,n,1001);
}
/*
Google OA, Harshit
*/
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}