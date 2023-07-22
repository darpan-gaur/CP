#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;

int getPrime(int n)
{
    int ctr = 0;
    for (int i = 2; i*i <= n; i++)
    {
        if (n%i != 0)
            continue;
        ctr++;
        while(n%i==0)
            n=n/i;
    }
    if (n >= 2)  //number itself is prime
        ctr++;

    return ctr;
}

int mem(vector<vector<int>> grid, int i, int j, vector<vector<int>>&dp)
{
    if (i >= grid.size() || j >= grid.size())
        return 1e9;

    if (i == grid.size() - 1 && j == grid.size() - 1)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int p = getPrime(grid[i][j]);
    dp[i][j] = 1e9;
    for (int k = 0; k <= p; k++)
    {
        for (int l = 0; l <= p-k; l++)
        {
            if (k==0 && l ==0)
                continue;
            dp[i][j] = min(dp[i][j], mem(grid,i+k,j+l,dp));
        }
    }
    dp[i][j] += floor(sqrt(grid[i][j]));
    return dp[i][j];
}

void solve(){
    ll n,i,j;
    cin >> n;
    vector<vector<int>> grid(n, vector<int> (n));
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) cin >> grid[i][j];
    }
    vector<vector<int>> dp(n, vector<int> (n,-1));
    cout << mem(grid, 0, 0, dp) << "\n";
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
Given NxN grid G and each cell of grid contains an integer. In one setp you can travel from
any cell Gi1j1 to Gi2j2 if abs(i1-i2) + abs(j1-j2) <=p at a cost of floor(sqrt(Gi1j1)). 
Here p is number of unique prime factors of the integer at Gi1j1.
Find the minimum cost to move from top left corner cell to bottom right corner cell, no
matter how many steps you take.

Constraints:
- 1<=T<=5
- 1<=N<=1000
- 2<=Gij<=10^6
- 1<=i,j<=N

Input Format:
- T : number of test cases
- N : size of grid
- N lines of N integers each

Sample Input:
2
3
13 12 15
5 6 9
2 4 8
3
2 3 5
30 4 6
5 2 8
Sample Output:
7
5

Sample Input:
2
3
18 3 4
6 5 9
13 20 14
3
18 10 20
14 2 5
14 19 10
Sample Output:
9
7

Sample Input:
2
3
14 20 4
19 12 5
20 15 12
3
3 6 3
6 18 18
4 15 9
Sample Output:
6
6
*/