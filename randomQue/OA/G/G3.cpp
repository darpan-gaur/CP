#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;

const int N = 100005, M = 1000000007;

int mul(long long x, long long y) {
    return x * y % M;
}

int pow(int x, int y) {
    int r = 1;
    for (; y; y >>= 1) {
        if (y & 1) {
            r = mul(r, x);
        }
        x = mul(x, x);
    }
    return r;
}

int rev(int x) {
    return pow(x, M - 2);
}
        
int C(const vector<int> &f, const vector<int> &rf, int x, int y) {
    return mul(mul(f[x], rf[y]), rf[x - y]);
}


vector<int> f(N), rf(N);

void solve(){
    int n,k,i;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> fre(26,0);
    for (i=0;i<n;i++) {
        fre[s[i]-'a']++;
    }
    map<int, int> count;
    for (i=0;i<26;i++) {
        if (fre[i]) count[fre[i]]++;
    }
    int res=1;
    for (auto t = count.rbegin(); k && t!=count.rend(); t++) {
        ll temp = min(k, t->second);
        res = mul(res, mul(pow(t->first, temp), C(f, rf, t->second, temp)));
        k -= temp;
    }
    cout << (k ? 0: res) << "\n";
    // cout << C(f, rf, 5, 2) << "\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    // pre computaion for nCr
    for (int i=f[0]=rf[0]=1; i < N; i++) {
        f[i] = mul(f[i-1], i);
        rf[i] = rev(f[i]);
    }
    while (t--){
        solve();
    }
    return 0;
}

/*
A subsequence of a string is a new string that is formed by deleting some (or none) of the characters 
from the original string, without changing the order of the remaining characters.
A special subsequence of a string is subsequence that has the following properties:
    - It has length exactly K.
    - It contains all Unique characters.
    - The sum of frequencies of all the characters in the subsequence is the maximum possible 
      sum among all special subsequence of length k.
Given a String S and an integer K, find the number of distinct special subsequences of the string. 
Since the number of special subsequences can be large, print the answer modulo 1e9 + 7.
Input Format:
- T - number of test cases
- N - length of string
- K
- S - string
Output Format:
For each test case, print the required answer in a new line.

Constraints:
- 1 <= T <= 10
- 1 <= N <= 10^5
- 1 <= K <= N
- S contains only lowercase English letters.

Sample Input:
1
5
4
cppbg
Sample Output: 2

Sample Input:
1
12
8
fpbavjsmppdt
Sample Output: 108

Sample Input:
1
16
7
ppzfsncqyzmuwrcv
Sample Output: 1680
*/