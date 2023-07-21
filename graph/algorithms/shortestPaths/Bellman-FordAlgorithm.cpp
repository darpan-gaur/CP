#include <iostream>
#include <vector>
#include <climits>  // INT_MAX

using namespace std;

// input weighted graph
void inputGraph(vector<pair<int, int>> adj[], int n, int m) {
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }
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

// Bellman-Ford algorithm
vector<int> bellmanFord(vector<pair<int, int>> adj[], int n, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    // n-1 iterations
    for (int i=0; i<n-1; i++) {
        for (int u=0; u<n; u++) {
            for (auto x: adj[u]) {
                if (dist[u]!=INT_MAX && dist[u] + x.second < dist[x.first]){
                    dist[x.first] = dist[u] + x.second;
                }
            }
        }
    }

    // check for negative weight cycle
    bool negCycle = false;
    for (int u=0; u<n; u++) {
        for (auto x: adj[u]) {
            if (dist[u]!=INT_MAX && dist[u] + x.second < dist[x.first]) {
                negCycle = true;
                break;
            }
        }
    }
    if (negCycle) {
        cout << "Negative weight cycle detected!" << endl;
    }
    return dist;
}

int main() {
    int n, m, src, dest;
    cin >> n >> m >> src >> dest;
    vector<pair<int, int>> adj[n];
    inputGraph(adj, n, m);
    printGraph(adj, n);
    vector<int> dist = bellmanFord(adj, n, src-1);
    // for (int i=0; i<n; i++) {
    //     cout << dist[i] << " ";
    // }
    // cout << endl;
    cout << dist[dest-1] << endl;
    return 0;
}