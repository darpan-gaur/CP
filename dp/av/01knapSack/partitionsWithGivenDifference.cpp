/*
https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628
*/

#include <iostream> 

using namespace std;

int mod = 1e9+7;

// Recursive
int Recursive(int arr[], int n, int diff, int sum1, int sum2) {
    // base case
    if (n == 0) {
        if ((sum1-sum2) == diff) {
            return 1;
        }
        return 0;
    }
    // recursive calls
    // remeber to take mod
    int count = 0;
    count += Recursive(arr, n-1, diff, sum1+arr[n-1], sum2);
    count = count%mod;
    count += Recursive(arr, n-1, diff, sum1, sum2+arr[n-1]);
    count = count%mod;
    return count;
}

// Recursive 2 -> count subset sum = (sum+diff)/2
int Recursive2(int arr[], int n, int sum) {
    // base condition
    if (n==0) {
        return (sum==0);
    }

    // choice diagram
    if (arr[n-1] <= sum) {
        return (Recursive2(arr, n-1, sum-arr[n-1]) + Recursive2(arr, n-1, sum)) % mod;
    }

    return Recursive2(arr, n-1, sum) % mod;
}

// Memoization
int Memoization(int arr[], int n, int diff, int sum1, int sum2, int **dp) {
    // base case
    if (n == 0) {
        if ((sum1-sum2) == diff) {
            return 1;
        }
        return 0;
    }
    // check if already calculated
    if (dp[n][sum1] != -1) {
        return dp[n][sum1];
    }
    // recursive calls
    int count = 0;
    count += Memoization(arr, n-1, diff, sum1+arr[n-1], sum2, dp);
    count = count%mod;
    count += Memoization(arr, n-1, diff, sum1, sum2+arr[n-1], dp);
    count = count%mod;
    dp[n][sum1] = count;
    return count;
} 

// Memoization 2 -> count subset sum = (sum+diff)/2
int Memoization2(int arr[], int n, int sum, int **dp) {
    // base condition
    if (n==0) {
        return (sum==0);
    }

    // check if already calculated
    if (dp[n][sum] != -1) {
        return dp[n][sum];
    }

    // choice diagram
    if (arr[n-1] <= sum) {
        return dp[n][sum] = (Memoization2(arr, n-1, sum-arr[n-1], dp) + Memoization2(arr, n-1, sum, dp)) % mod;
    }

    return dp[n][sum] = Memoization2(arr, n-1, sum, dp) % mod;
}

// top down
int TopDown(int arr[], int n, int diff) {
    int sum = 0;
    for (int i=0; i<n; i++) {
        sum += arr[i];
    }
    int sum1 = (sum+diff)/2;
    if ((sum+diff)%2 != 0) {
        // cout << 0 << endl;
        return 0;
    }
    int dp[n+1][sum1+1];
    for (int i=0; i<=n; i++) {
        dp[i][0] = 1;
    }
    for (int i=1; i<=sum1; i++) {
        dp[0][i] = 0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=sum1; j++) {
            if (arr[i-1] <= j) {
                dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]) % mod;
            } else {
                dp[i][j] = dp[i-1][j] % mod;
            }
        }
    }
    return dp[n][sum1];
}

int main() {
    int n, diff;
    cin >> n >> diff;
    int arr[n];
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    /*
    12 29
    13 8 11 14 0 14 2 11 12 7 3 11
    Ans :- 0

    14 50
    12 4 14 7 10 9 10 7 12 4 1 1 5 0
    Ans :- 120
    */
    cout << "Recursive :- " << Recursive(arr, n, diff, 0, 0) << endl;

    // recursive 2
    if ((sum+diff)%2==0) cout << "Recursive2 :- " << Recursive2(arr, n, (sum+diff)/2) << endl;
    else cout << "Recursive2 :- " << 0 << endl;
    // memoization
    int **dp = new int*[n+1];
    for (int i=0; i<=n; i++) {
        dp[i] = new int[sum+1];
        for (int j=0; j<=sum; j++) {
            dp[i][j] = -1;
        }
    }
    cout << "Memoization :- " << Memoization(arr, n, diff, 0, 0, dp) << endl;
    
    // memoization 2
    int **dp2 = new int*[n+1];
    for (int i=0; i<=n; i++) {
        dp2[i] = new int[(sum+diff)/2+1];
        for (int j=0; j<=(sum+diff)/2; j++) {
            dp2[i][j] = -1;
        }
    }
    if ((sum+diff)%2==0) cout << "Memoization2 :- " << Memoization2(arr, n, (sum+diff)/2, dp2) << endl;
    else cout << "Memoization2 :- " << 0 << endl;

    // top down
    cout << "TopDown :- " << TopDown(arr, n, diff) << endl;
    return 0;
}