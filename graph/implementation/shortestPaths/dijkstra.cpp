#include <iostream>
#include <vector>
#include <queue>
#include <climits>  // INT_MAX
#include <set>      // set

using namespace std;

// input weighted graph
void inputGraph(vector<pair<int, int>> adj[], int n, int m) {
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // u--; v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

vector<int> dijkstra(vector<pair<int, int>> adj[], int n, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    set<pair<int, int>> s;
    s.insert({0, src});
    while (!s.empty()) {
        auto top = *(s.begin());
        int d = top.first;
        int u = top.second;
        s.erase(s.begin());
        for (auto x: adj[u]) {
            if (d + x.second < dist[x.first]) {
                auto f = s.find({dist[x.first], x.first});
                // if record exists, erase it
                if (f != s.end()) {
                    s.erase(f);
                }
                dist[x.first] = d + x.second;
                s.insert({dist[x.first], x.first});
            }
        }
    }
    return dist;
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

    int src;
    cin >> src;
    // src--;
    vector<int> dist = dijkstra(adj, n, src);
    for (int i=0; i<n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
