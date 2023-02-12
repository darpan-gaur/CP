#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
	ll n,ans=0,ai,aip,i;
	cin >> n;
	cin >> aip;
	for (i=1;i<n;i++) {
		cin >> ai;
		if (aip-ai>0) ans += aip-ai;
		else aip = ai;
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