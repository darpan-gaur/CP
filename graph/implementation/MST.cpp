#include <iostream>
#include <vector>
#include <climits>  // INT_MAX
#include <set>      // set

using namespace std;

// input weighted graph
void inputGraph(vector<pair<int, int>> adj[], int n, int m) {
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

// Prim's algorithm
// Time complexity: O(n^2)
vector<pair<pair<int, int>, int>> primAlgo(vector<pair<int, int>> adj[], int n) {
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);

    int src = 0;
    key[src] = 0;
    parent[src] = -1;
    for (int i=0; i<n-1; i++) {
        int u = -1;
        // find u -> min key[u] in key[] such that u is not in mst[]
        for (int j=0; j<n; j++) {
            if (!mst[j] && (u == -1 || key[j] < key[u])) {
                u = j;
            }
        }
        // add u to mst
        mst[u] = true;
        // update key[v] for all v adjacent to u
        for (auto x: adj[u]) {
            int v = x.first;
            int w = x.second;
            if (!mst[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
            }
        }
    }
    vector<pair<pair<int, int>, int>> mstEdges;
    for (int i=1; i<n; i++) {
        mstEdges.push_back({{parent[i], i}, key[i]});
    }
    return mstEdges;
}

// Prim's algorithm
// Time complexity: O(mlogn)
vector<pair<pair<int, int>, int>> primAlgoFast(vector<pair<int, int>> adj[], int n) {
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);

    int src = 0;
    key[src] = 0;
    parent[src] = -1;
    set<pair<int, int>> s;
    s.insert({0, src});
    while (!s.empty()) {
        auto top = *(s.begin());
        int u = top.second;
        s.erase(s.begin());
        mst[u] = true;
        for (auto x: adj[u]) {
            int v = x.first;
            int w = x.second;
            if (!mst[v] && w < key[v]) {
                auto f = s.find({key[v], v});
                // if record exists, erase it
                if (f != s.end()) {
                    s.erase(f);
                }
                key[v] = w;
                parent[v] = u;
                s.insert({key[v], v});
            }
        }
    }
    vector<pair<pair<int, int>, int>> mstEdges;
    for (int i=1; i<n; i++) {
        mstEdges.push_back({{parent[i], i}, key[i]});
    }
    return mstEdges;
}


// print weighted graph
void printGraph(vector<pair<int, int>> adj[], int n) {
    for (int i=0; i<n; i++) {
        cout << i+1 << ": ";
        for (auto u: adj[i]) {
            cout << "(" << u.first+1 << "," << u.second << ") ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    inputGraph(adj, n, m);

    printGraph(adj, n);

    cout << "prims algo O(n^2) " << endl;
    vector<pair<pair<int, int>, int>> mstEdges = primAlgo(adj, n);
    for (auto x: mstEdges) {
        cout << x.first.first+1 << " " << x.first.second+1 << " " << x.second << endl;
    }

    cout << "prims algo O(mlogn) " << endl;
    vector<pair<pair<int, int>, int>> mstEdgesFast = primAlgoFast(adj, n);
    for (auto x: mstEdgesFast) {
        cout << x.first.first+1 << " " << x.first.second+1 << " " << x.second << endl;
    }
    return 0;
}