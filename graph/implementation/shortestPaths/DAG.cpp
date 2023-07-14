#include <iostream>
#include <vector>
#include <stack>
#include <climits>  // INT_MAX

using namespace std;

// input weighted graph
void inputGraph(vector<pair<int, int>> adj[], int n, int m) {
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // u--; v--;
        adj[u].push_back({v, w});
    }
}   

void topoSort(int s, vector<bool>& visited, stack<int>& st, vector<pair<int, int>> adj[]) {
    visited[s] = true;
    for (auto u: adj[s]) {
        if (!visited[u.first]) {
            topoSort(u.first, visited, st, adj);
        }
    }
    st.push(s);
}

vector<int> shortestPath(int src, vector<pair<int, int>> adj[], int n) {
    // topo sort
    vector<bool> visited(n, false);
    stack<int> st;
    for (int i=0;i<n;i++) {
        if (!visited[i]) {
            topoSort(i, visited, st, adj);
        }
    }
    
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    while (!st.empty()) {
        int s = st.top();
        st.pop();
        if (dist[s] != INT_MAX) {
            for (auto u: adj[s]) {
                if (dist[u.first] > dist[s] + u.second) {
                    dist[u.first] = dist[s] + u.second;
                }
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
        cout << "\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    /*
    6 7
    0 1 2
    0 4 1
    4 5 4
    4 2 2
    1 2 3
    2 3 6
    5 3 1
    */
    inputGraph(adj, n, m);
    
    printGraph(adj, n);

    int src = 0;
    vector<int> dist = shortestPath(src, adj, n);
    for (auto u: dist) {
        cout << u << " ";
    }
    cout << "\n";
    return 0;
}