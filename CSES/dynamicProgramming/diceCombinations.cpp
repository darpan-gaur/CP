#include <iostream>

using namespace std;

int mod = 1e9 + 7;

// recursive
int recursive(int n) {
	if (n == 0) return 1;
	if (n < 0) return 0;
	int ans = 0;
	for (int i = 1; i <= 6; i++) {
		ans = (ans + recursive(n - i)) % mod;
	}
	return ans;
}

// memoization
int memoization(int n, int *dp) {
	if (n == 0) return 1;
	if (n < 0) return 0;
	if (dp[n] != -1) return dp[n];
	int ans = 0;
	for (int i = 1; i <= 6; i++) {
		ans = (ans + memoization(n - i, dp)) % mod;
	}
	return dp[n] = ans;
}

int main() {
	int n,i,j;
	cin >> n;

	int dp[n+1]={0};
	dp[0] = 1;

	for (i=1;i<=n;i++) {
		// checking for all outcome of dice
		for (j=1;j<=6;j++) {
			if (i>=j) {
				dp[i] = (dp[i] + dp[i-j])%mod; 
			}
		}
	}
	cout << dp[n] << "\n";

	// extra for fun
	cout << "recursive :- " << recursive(n) << "\n";

	int dp2[n+1];
	for (i=0;i<=n;i++) dp2[i] = -1;
	cout << "memoization :- " << memoization(n, dp2) << "\n";
	
	return 0;
}