#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
	ll n,ans=1,a=2,mod=1e9+7;
	cin >> n;
	while (n>0) {
		if (n%2) ans = (ans*a)%mod;
		a = (a*a)%mod;
		n /= 2;
	}
	cout << ans << "\n";
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