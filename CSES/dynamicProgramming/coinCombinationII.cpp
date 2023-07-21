#include <iostream>

using namespace std;

const int mod = 1e9+7;

// recursive :- TLE - 5/14 Passed
// int recursive(int arr[], int n, int x) {
// 	// base case
// 	if (x==0) return 1;
// 	if (n==0) return 0;
 
// 	if (x >= arr[n-1]) {
// 		return (recursive(arr, n, x-arr[n-1]) + recursive(arr, n-1, x)) % mod;
// 	}
// 	return recursive(arr, n-1, x)%mod;
// }

// memoization :- TLE
// int **dp;
// int memoization(int arr[], int n, int x) {
// 	// base case
// 	if (x==0) return 1;
// 	if (n==0) return 0;

// 	if (dp[n][x]!=-1) return dp[n][x]; 

// 	if (x>=arr[n-1]) {
// 		return dp[n][x] = (memoization(arr, n, x-arr[n-1]) + memoization(arr, n-1, x)) % mod;
// 	}
// 	return dp[n][x] = memoization(arr, n-1, x);

// }

// top down :- Time :- 0.51
// int topDown(int arr[], int n, int x) {
// 	int i,j;
// 	int **dp = new int*[n+1];
// 	for (i=0;i<=n;i++) {
// 		dp[i] = new int[x+1];
// 	}
// 	for (i=0;i<=x;i++) dp[0][i] = 0;
// 	for (i=0;i<=n;i++) dp[i][0] = 1;

// 	for (i=1;i<=n;i++) {
// 		for (j=1;j<=x;j++) {
// 			if (j>=arr[i-1]) {
// 				dp[i][j] = (dp[i][j-arr[i-1]] + dp[i-1][j]) % mod;
// 			}
// 			else dp[i][j] = dp[i-1][j];
// 		}
// 	}

// 	return dp[n][x];
// }

int main() {
	int n,x,i,j;
	cin >> n >> x;
	int coins[n];
	for (i=0;i<n;i++) cin >> coins[i];

	int dp[x+1]={0};
	dp[0] = 1;

	for (i=1;i<=n;i++) {
		for (j=1;j<=x;j++) {
			if (j>=coins[i-1]) {
				dp[j] = (dp[j] + dp[j-coins[i-1]]) % mod;
			}
		}
	}
	cout << dp[x] << "\n";
	
	// extra for fun 
	// cout << recursive(coins, n, x) << "\n";	

	// memoization
	// dp = new int*[n+1];
	// for (i=0;i<=n;i++) {
	// 	dp[i] = new int[x+1];
	// 	for (j=0;j<=x;j++) dp[i][j] = -1;
	// }
	// cout << memoization(coins, n, x) << "\n";
	
	// top down
	// cout << topDown(coins, n, x) << "\n";

	return 0;
}