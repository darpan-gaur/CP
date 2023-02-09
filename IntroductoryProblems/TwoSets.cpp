#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
	ll n,sum,i,c=1;
	cin >> n;
	if (n%4==0) {
		cout << "YES\n";
		cout << n/2 << "\n";
		for (i=0;i<n/2;i++) {
			cout << c << " ";
			if (i%2) c++;
			else c+=3;

		}
		cout << "\n" << n/2 << "\n";
		c = 2;
		for (i=0;i<n/2;i++) {
			cout << c << " ";
			if (i%2) c+=3;
			else c++;
		}cout << "\n";
	}
	 else if (n%4==3) {
		cout << "YES\n";
		cout << n/2+1 << "\n";
		cout << "1 2 ";
		c = 4;
		for (i=1;i<n/2;i++) {
			cout << c << " ";
			if (i%2) c+=3;
			else c++;
		}
		cout << "\n" << n/2 << "\n";
		cout << "3 ";
		c=5;
		for (i=1;i<n/2;i++) {
			cout << c << " ";
			if (i%2) c++;
			else c+=3; 
		}cout << "\n";
	}
	else cout << "NO\n";
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