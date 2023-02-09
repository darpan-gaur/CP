#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
	ll n,i,ai;
	cin >> n;
	vector<int> v(n+1,0);
	for (i=0;i<n-1;i++){
		cin >> ai;
		v[ai]++;
	}
	for (i=1;i<=n;i++) if (!v[i]) cout << i << "\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }

    return 0;
}