#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
	ll a,b;
	cin >> a >> b;
	if (2*a-b>=0 && 2*b-a>=0 && (2*a-b)%3==0 && (2*b-a)%3==0) {
		cout << "YES\n";
	}else {
		cout << "NO\n";
	}
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