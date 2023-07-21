#include <iostream>
#include <vector>

using namespace std;

// input unweighted graph 
void inputGraph(vector<int> adj[], int n, int m) {
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        // u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

// print graph
void printGraph(vector<int> adj[], int n) {
    for (int i=0; i<n; i++) {
        cout << i << " -> ";
        for (auto it: adj[i]) {
            cout << it << " ";
        }
        cout << endl;
    }
}

// dfs
void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &tin, vector<int> &low, int &timer, int parent, vector<vector<int>> &bridges) {
    visited[node] = true;
    tin[node] = low[node] = timer++;
    for (auto nbr: adj[node]) {
        if (nbr == parent) continue;
        if (!visited[nbr]) {
            dfs(nbr, adj, visited, tin, low, timer, node, bridges);
            low[node] = min(low[node], low[nbr]);
            // check for bridge
            if (low[nbr] > tin[node]) {
                bridges.push_back({node, nbr});
            }
        } else {
            // back edge
            low[node] = min(low[node], tin[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<int> adj[], int n, int m) {
    // Time Complexity: O(N + M)
    // Space Complexity: O(N)
    vector<vector<int>> bridges;
    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    vector<bool> visited(n, false);
    int timer = 0;
    int parent = -1;

    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, tin, low, timer, parent, bridges);
        }
    }

    return bridges;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    inputGraph(adj, n, m);
    printGraph(adj, n);

    vector<vector<int>> bridges = findBridges(adj, n, m);
    cout << "Bridges in graph: " << endl;
    for (auto it: bridges) {
        cout << it[0] << " " << it[1] << endl;
    }

    return 0;
}