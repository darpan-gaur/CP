#include <iostream>
#include <climits> 	// INT_MAX

using namespace std;

// int recursive(int arr[], int n, int x) {
// 	// base case
// 	if (x==0) return 0;
// 	if (n==0) return INT_MAX-1;

// 	if (x>=arr[n-1]) {
// 		return min(1+recursive(arr, n, x-arr[n-1]), recursive(arr, n-1, x));
// 	}
// 	return recursive(arr, n-1, x);
// }

// int dp[101][1000001];
// // TLE
// int memoization(int arr[], int n, int x) {
// 	// base case
// 	if (x==0) return 0;
// 	if (n==0) return INT_MAX-1;

// 	if (dp[n][x]!=-1) return dp[n][x];
// 	if (x>=arr[n-1]) {
// 		return dp[n][x] = min(1+memoization(arr, n, x-arr[n-1]), memoization(arr, n-1, x));
// 	}
// 	return dp[n][x] = memoization(arr, n-1, x);
// }

// int topDown(int coins[], int n, int x) {
// 	int i,j;
// 	int dp[n+1][x+1];
// 	for (i=0;i<=n;i++) {
// 		for (j=0;j<=x;j++) dp[i][j] = 0;
// 	}
// 	for (i=1;i<=x;i++) dp[0][i] = INT_MAX-1;
// 	for (i=1;i<=n;i++) {
// 		for (j=1;j<=x;j++) {
// 			if (j>=coins[i-1]) {
// 				dp[i][j] = min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
// 			}else {
// 				dp[i][j] = dp[i-1][j];
// 			}
// 		}
// 	}
// 	return dp[n][x];
// }

int main() {
	int n,x,i,j;
	cin >> n >> x;
	int coins[n];
	for (i=0;i<n;i++) cin >> coins[i];

	int dp[x+1];
	for (i=1;i<=x;i++) dp[i] = INT_MAX-1;
	dp[0] = 0;
	for (i=1;i<=n;i++) {
		for (j=1;j<=x;j++) {
			if (j>=coins[i-1]) dp[j] = min(1+dp[j-coins[i-1]], dp[j]);
		}
	}
	cout << (dp[x] == (INT_MAX-1) ? -1 : dp[x]) << "\n";
	
	// extra for fun
	// cout << recursive(coins, n, x) << "\n";

	// memoization
	// for (i=0;i<=n;i++) {
	// 	for (j=0;j<=x;j++) dp[i][j] = -1;
	// }
	// cout << memoization(coins, n, x);

	// top down
	// cout << topDown(coins, n, x) << "\n";
	return 0;
}