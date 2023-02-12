#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
	ll y,x;
	cin >> y >> x;
	if (y>x) {
		cout <<  ((y%2) ? (y-1)*(y-1)+x:y*y-x+1) << "\n"; 
	}
	else {
		cout << ((x%2==0) ? (x-1)*(x-1)+y:x*x-y+1) << "\n";
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