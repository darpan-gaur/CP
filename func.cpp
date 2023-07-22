#include <bits/stdc++.h>
#define ll long long

using namespace std;

// vector pair sort


//basis of first element of pairs in ascending order.
// sort(vect.begin(), vect.end());

//basis of second element of pairs in ascending order. 
// bool cmp(pair<ll,ll> a, pair<ll,ll> b){
//     return (a.second < b.second);
// }
// sort(vect.begin(), vect.end(), cmp);

// basis of first element of pairs in descending order.
// sort(vect.rbegin(), vect.rend());

// basis of second element of pairs in descending order.
// bool cmp(pair<ll,ll> a, pair<ll,ll> b){
//     return (a.second > b.second);
// }
// sort(vect.begin(), vect.end(), cmp);

// first : - descending, second :- ascending
bool cmp1(pair<ll,ll> a, pair<ll,ll> b)
{
    if(a.first == b.first)
        return a.second < b.second;
        
    return a.first > b.first;
}
// sort(v.begin(),v.end(),cmp1);




// Check if a number is prime or not
// O(root(n))
bool prime(int n) {
	if (n<2) return false;
	for (int x = 2;x*x<=n; x++) if (n%x==0) return false;
	return true;
}	

// seive of erarostheses
// int n;
// vector<bool> is_prime(n+1, true);
// is_prime[0] = is_prime[1] = false;
// for (int i = 2; i * i <= n; i++) {
//     if (is_prime[i]) {
//         for (int j = i * i; j <= n; j += i)
//             is_prime[j] = false;
//     }
// }

// Return a vector conrtaining prime factorization of n
// O(root(n))
vector<int> factor(int n){
    vector<int> f;
    for (int x = 2; x*x <= n; x++) {
        while (n%x == 0){
            f.push_back(x);
            n /= x;
        }
    }
    if (n>1) f.push_back(n);
    return f;
}

//Euclid's Algorithm
// O(log(n)) where n = min(a,b)
// Worst case when a and b are consecutive fibonacci numbers
int gcd(int a,int b){
    if (b==0) return a;
    return gcd(b,a%b);
}

// x^n in O(logn)
ll binpow(ll a, ll b){
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res*a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

// x^n mod m 
ll binpowmod(ll a, ll b, ll m){
    a %= m;
    ll res = 1;
    while (b > 0){
        if (b & 1){
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// remove duplicates form a vector
// a.resize(unique(a.begin(), a.end()) - a.begin());

void solve(){
    ll n,i,ai;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (i=0;i<n;i++) {
        cin >> ai;
        v[i] = {ai,i};
    }
    sort(v.rbegin(),v.rend());
    for (auto x:v) cout << x.first << " " << x.second << "\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }

    // cout << prime(12) << "\n";

    // for (auto x:factor(123)){
    //     cout << x << " ";
    // }

    // cout << gcd(36, 18) << "\n";

    return 0;
}