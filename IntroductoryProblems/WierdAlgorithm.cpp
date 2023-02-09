#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
	ll n;
	cin >> n;
	while (n>1){
		cout << n << " ";
		if (n%2) {
			n = 3*n+1;
		}else n /= 2;
	}
	cout << n << "\n";
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