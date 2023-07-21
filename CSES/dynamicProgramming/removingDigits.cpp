#include <iostream>
#include <climits> 	// INT_MAX

using namespace std;

const int mod = 1e9+7;

// recursive
// int recursive(int n) {
// 	// base case
// 	if (n==0) return 0;

// 	// get digits
// 	int temp = n;
// 	int ans = 1e9;
// 	while (temp) {
// 		if (temp%10 && n>=temp%10) ans = min(ans, 1+recursive(n-temp%10));
// 		temp = temp/10;
// 	}
// 	return ans;
// }

// memoization
// int dp[1000001];
// int memoization(int n) {
// 	// base case
// 	if (n==0) return 0;

// 	if (dp[n]!=-1) return dp[n];

// 	// get digits
// 	int temp = n;
// 	int ans = 1e9;
// 	while (temp) {
// 		if (temp%10 && n>=temp%10) ans = min(ans, 1+memoization(n-temp%10));
// 		temp = temp/10;
// 	}
// 	return dp[n]=ans;
// }

// greedy also works here :- subtract largest digit

int main() {
	int n,i,ans,temp;
	cin >> n;
	int dp[n+1]={0};
	for (i=1;i<=n;i++) {
		ans = INT_MAX;
		temp = i;
		while (temp) {
			if (temp%10 && i>=temp%10) ans = min(ans, 1+dp[i-temp%10]);
			temp = temp / 10;
		}
		dp[i] = ans;
	}
	cout << dp[n] << "\n";
	
	// extra for fun 
	// cout << recursive(n) << "\n";

	// memoization
	// for (i=0;i<=n;i++) dp[i] = -1;
	// cout << memoization(n) << "\n";
	return 0;
}