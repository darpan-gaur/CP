#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){ 
	ll n, m ,k,i,j,ans=0;
	cin >> n >> m >> k;
	vector<int> v(n);
	vector<int> v1(m);
	for (i=0;i<n;i++) cin >> v[i];
	for (i=0;i<m;i++) cin >> v1[i];
	sort(v.begin(),v.end());
	sort(v1.begin(),v1.end());
	j=0;
	cout << "HI\n";
	for (i=0;i<n;i++) {
		cout << v[i] << " " << v1[j] << "\n";
		if (j>=m) break;
		if (abs(v[i]-v1[j])<=k) {
			ans++;
		}
		else if (v[i] > v1[j]) {
			while (v[i] > v1[j]) {
				if (abs(v[i]-v1[j])<=k) {
					ans++;
					break;
				}
				j++;
			}	
		}j++;
	}cout << ans << "\n";
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