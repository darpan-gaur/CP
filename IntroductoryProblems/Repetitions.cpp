#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
	int i,n,c=1,ans=0;
	string s;
	cin >> s;
	n = s.size();
	for (i=1;i<n;i++) {
		if (s[i]!=s[i-1]){
			ans = max(ans,c);
			c = 1;
		}
		else c++;
	}
	ans = max(ans,c);
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