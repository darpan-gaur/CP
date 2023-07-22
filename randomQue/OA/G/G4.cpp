#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;

void adjust(multiset<int> &s1, multiset<int> &s2) {
    while (s1.size() > s2.size() + 1) {
        s2.insert(-*s1.begin());
        s1.erase(s1.begin());
    }
    while (s2.size() > s1.size() + 1) {
        s1.insert(-*s2.begin());
        s2.erase(s2.begin());
    }
}

void addNum(int num, multiset<int> &s1, multiset<int> &s2) {
    if (s1.empty()) {
        s2.insert(num);
    } else if (s2.empty()) {
        s1.insert(-num);
    } else if (num >= *s2.begin()) {
        s2.insert(num);
    } else {
        s1.insert(-num);
    }
    adjust(s1, s2);
}

void delNum(int num, multiset<int> &s1, multiset<int> &s2) {
    auto t = s2.find(num);
    if (t != s2.end()) {
        s2.erase(t);
    } else {
        t = s1.find(-num);
        if (t != s1.end()) {
            s1.erase(t);
        }
    }
    adjust(s1, s2);
}
    
int findMedian(multiset<int> &s1, multiset<int> &s2) {
    return s1.size() > s2.size() ? (-*s1.begin()) : *s2.begin();
}

ll dfs(int d, int x, int f, vector<vector<int>>& adj, vector<int>& c, multiset<int> &s1, multiset<int> &s2) {
    addNum(c[x], s1, s2);
    ll res=0;
    if ((++d) & 1) {
        res = findMedian(s1, s2);
    }
    // f :- parent
    for (auto u:adj[x]) {
        if (u!=f) {
            res += dfs(d, u, x, adj, c, s1, s2);
        }
    }
    delNum(c[x], s1, s2);
    return res;
}


void solve(){
    int n,i;
    cin >> n;
    vector<int> c(n);
    for (i=0;i<n;i++) {
        cin >> c[i];
    }
    vector<vector<int>> adj(n);
    for (i=1;i<n;i++) {
        int u,v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    multiset<int> s1,s2;
    cout << dfs(0,0,-1,adj,c,s1,s2) << "\n";
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

/*
Median Path
Given a tree of n nodes and n-1 edges. Edge node has a value, which  is stored in an array C.
Ci (i<=i<=n) denotes the value of node i.
Find the sum of the medians of all simple paths of odd length starting from node 1.
Notes :
    - Use 1 based indexing.
    - A simple path is a path with no repeated nodes.

Constraints :
    - T : 1<=T<=10
    - N : 1<=N<=10^5
    - C[i] : 1<=C[i]<=10^9

Sample Input :
2
5
7 6 9 10 1
1 2
2 3
1 4
2 5
6
1 2 3 1 5
1 4

Sample Output :
20
7
*/