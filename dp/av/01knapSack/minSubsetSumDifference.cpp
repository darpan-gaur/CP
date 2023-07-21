/*
https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
*/

#include <iostream>
#include <climits>  // for INT_MAX

using namespace std;

// recursive
// Time: O(2^n), Space: O(n)
// Two ways  
//      -> sum1 =0, sum2 = sum & (sum1+arr[i], sum2-arr[i]) || (sum1, sum2)
//      -> sum1 =0, sum2 =0 & (sum1+arr[i], sum2) || (sum1, sum2+arr[i])
int minDiffRecursive(int arr[], int n, int sum1, int sum2) {
    // base case
    if (n == 0) return abs(sum1 - sum2);

    // recursive calls
    int diff1 = minDiffRecursive(arr, n-1, sum1 + arr[n-1], sum2);
    int diff2 = minDiffRecursive(arr, n-1, sum1, sum2 + arr[n-1]);

    return min(diff1, diff2);
}

// memoization
int minDiffMemoization(int arr[], int n, int sum1, int sum2, int **dp) {
    // base case
    if (n == 0) return abs(sum1 - sum2);

    // check if already calculated
    if (dp[n][sum1] != -1) return dp[n][sum1];

    // recursive calls
    int diff1 = minDiffMemoization(arr, n-1, sum1 + arr[n-1], sum2, dp);
    int diff2 = minDiffMemoization(arr, n-1, sum1, sum2 + arr[n-1], dp);

    // store and return
    dp[n][sum1] = min(diff1, diff2);
    return dp[n][sum1];
}

// tabulation
int minDiffTabulation(int arr[], int n, int sum) {
    // create dp array
    bool **dp = new bool*[n+1];
    for (int i=0;i<=n;i++) {
        dp[i] = new bool[sum+1];
        dp[i][0] = true;
    }
    for (int i=1;i<=sum;i++) dp[0][i] = false;

    // fill dp array
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=sum;j++) {
            dp[i][j] = dp[i-1][j];
            if (arr[i-1] <= j) dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
        }
    }

    // find min diff
    int diff = INT_MAX;
    for (int i=0;i<=sum/2;i++) {
        if (dp[n][i]) diff = min(diff, sum - 2*i);
    }
    return diff;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++) cin >> arr[i];
    /*
    19
    884 868 7 957 783 1153 1133 567 990 639 185 224 303 187 420 1094 1013 831 321
    Answer: 1
    */
    int sum = 0;
    for (int i=0;i<n;i++) sum += arr[i];
    cout << minDiffRecursive(arr, n, 0, 0) << endl;

    // memoization
    int **dp = new int*[n+1];
    for (int i=0;i<=n;i++) {
        dp[i] = new int[sum+1];
        for (int j=0;j<=sum;j++) dp[i][j] = -1;
    }
    cout << minDiffMemoization(arr, n, 0, 0, dp) << endl;

    // tabulation
    cout << minDiffTabulation(arr, n, sum) << endl;
    return 0;
}