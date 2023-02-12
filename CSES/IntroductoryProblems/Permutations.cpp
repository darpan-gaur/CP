#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
	ll n,i,c=2;
	cin >> n;
	vector<int> v(n);
	if (n==1) {
		cout << "1\n";
		return;
	}
	for (i=0;i<n;i++) {
		v[i] = c;
		c+=2;
		if (c>n) c = 1;
	}
	for (i=0;i<n-1;i++) {
		if (abs(v[i]-v[i+1])==1) {
			cout << "NO SOLUTION\n";
			return;
		}
	}
	for (auto x:v) cout << x << " ";
	cout << "\n";
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