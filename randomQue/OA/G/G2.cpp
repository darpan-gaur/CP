#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;

void solve(){
    ll n,i;
    cin >> n;
    // cout << n << "\n";
    vector<ll> a(n);
    for (i=0;i<n;i++) cin >> a[i];
    // for (i=0;i<n;i++) cout << a[i] << " ";
    //     cout << "\n";
    vector<int> ind(n);
    for (i=0;i<n;i++) ind[i]=i;
    sort(ind.begin(), ind.end(), [&](const int &x, const int &y) {
        return a[x] < a[y];
    });
    vector<int> rev(n);
    // new index after sorting
    for (i=0;i<n;i++) {
        rev[ind[i]] = i;
    }
    vector<ll> pre(n+1, 0);
    for (i=1;i<=n;i++) {
        pre[i] = pre[i-1] + a[ind[i-1]];
    }
    ll q,c,k;
    cin >> q;
    // cout << q << "\n";
    while (q--) {
        cin >> c >> k;
        int s = 1, e = n;
        int res = 0;
        vector<int> v(k);
        for (i=0;i<k;i++) {
            cin >> v[i];
        }
        // for (i=0;i<k;i++) {
        //     cout << v[k] << " ";
        // }
        // cout << "\n";
        while (s <= e) {
            int mid = s + (e-s)/2;
            ll cost = pre[mid];
            int broken = 0;
            for (i=0;i<k;i++) {
                if (rev[v[i]-1]<mid) {
                    broken++;
                    cost -= a[v[i]-1];
                }
            }
            if (cost <= c) {
                res = max(res, mid-broken);
                s = mid+1;
            }else {
                e = mid-1;
            }
            // cout << res << " ";
        }
        cout << res << " ";
        // cout << "\n";
    }
    cout << "\n";

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
Maximum Collenction
Given N toys in a shop, each with a price represented by an array A. You have a certain amount
of money, C, that you can use to buy toys. There are also K toys that are broken and you don't
want to buy them. 
For each Q query, find the maximum number of toys you can buy with the amount you have while
avoiding broken toys.

Input Format
- T - number of test cases
- N - number of toys
- N space separated integers - prices of toys
- Q - number of queries
- C K i1 i2 ... iK - C - amount of money, K - number of broken toys, i1 i2 ... iK - indices of broken toys

Output Format
- Q lines - maximum number of toys you can buy for each query

Constraints
- 1 <= T <= 10
- 1 <= N <= 10^5
- 1 <= A[i] <= 10^6
- 1 <= Q <= 10^4
- 1 <= C <= 10^9
- 1 <= K <= 10
- 1 <= i1, i2, ..., iK <= N

Sample Input
1
10
7 3 6 8 2 1 4 9 5 10
4
10 2 2 5
15 1 1
20 3 1 2 1
100 0

Sample Output
3 5 5 10
*/