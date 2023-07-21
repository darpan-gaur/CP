#include <iostream>

using namespace std;

const int mod = 1e9+7;

// TLE, 7/13 passed
// int recursive(int arr[], int n, int x) {
// 	// base condition
// 	if (x==0) return 1;
// 	if (x<0) return 0;
 
// 	int ans=0;
// 	for (int i=0;i<n;i++) {
// 		if (x>=arr[i]) ans = (ans+recursive(arr, n, x-arr[i]))%mod;
// 	}
// 	return ans;
// }
 
// int dp[1000001];
// int memoization(int arr[], int n, int x) {
// 	if (x==0) return 1;
// 	if (x<0) return 0;
 
// 	if (dp[x]!=-1) return dp[x];
 
// 	int ans=0;
// 	for (int i=0;i<n;i++) {
// 		if (x>=arr[i]) ans = (ans+memoization(arr, n, x-arr[i]))%mod;
// 	}
// 	return dp[x] = ans;
// }

int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,x,i;
	cin >> n >> x;
	
	int coins[n];
	for (int i=0;i<n;i++) cin >> coins[i];

	int dp[x+1] = {0};
	dp[0] = 1;
	for (int i=1;i<=x;i++) {
		long long ans = 0;
		for (int j=1;j<=n;j++) {
			if (i >= coins[j-1]) {
				ans +=  dp[i-coins[j-1]];
			}
		}
		dp[i] = ans%mod;
	}
	cout << dp[x] << "\n";

	// extra for fun 
	// cout << recursive(coins, n, x) << "\n";
 
	// for (i=0;i<=x;i++) dp[i] = -1;
	// cout << memoization(coins, n, x) << "\n";
	return 0;
}