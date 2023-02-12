#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
	ll n,i,ans=0;
	cin >> n;
	i = 5;
	while (i<=n) {
		ans += n/i;
		i = i*5;
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