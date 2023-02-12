#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
	int n,i,c=0,j;
	string s;
	cin >> s;
	n = s.size();
	vector<int> v(26,0);
	for (i=0;i<n;i++) {
		v[s[i]-'A']++;
	}
	for (i=0;i<26;i++) {
		if (v[i]%2) c++;
	}
	if (c==0) {
		if (n%2) {
			cout << "NO SOLUTION\n";
		}
	}else if (c==1) {
		if (n%2==0) {
			cout << "NO SOLUTION\n";
		}
	}else {
		cout << "NO SOLUTION\n";
	}
	c=-1;
	for (i=0;i<26;i++){
		if (v[i]%2) c=i;
		for (j=0;j<v[i]/2;j++) {
			if (v[i]>1) cout << (char)('A'+i) ;
		}
	}
	if (c!=-1) cout << (char)('A'+c);
	for (i=25;i>=0;i--){
		for (j=0;j<v[i]/2;j++) {
			if (v[i]>1) cout << (char)('A'+i) ;
		}
	}
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