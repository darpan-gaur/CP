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
void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &tin, vector<int> &low, int &timer, int parent, vector<int> &isArticulationPoint) {
    visited[node] = true;
    tin[node] = low[node] = timer++;
    int children = 0;
    for (auto nbr: adj[node]) {
        if (nbr == parent) continue;
        if (!visited[nbr]) {
            dfs(nbr, adj, visited, tin, low, timer, node, isArticulationPoint);
            low[node] = min(low[node], low[nbr]);
            // check for articulation point
            if (low[nbr] >= tin[node] && parent != -1) {
                isArticulationPoint[node] = true;
            }
            children++;
        } else {
            // back edge
            low[node] = min(low[node], tin[nbr]);
        }
    }
    if (parent == -1 && children > 1) {
        isArticulationPoint[node] = true;
    }
}

vector<int> articulationPoints(vector<int> adj[], int n, int m) {
    // Time Complexity: O(N + M)
    // Space Complexity: O(N)
    vector<int> tin(n, -1); // time of insertion (discovery time)
    vector<int> low(n, -1);
    vector<bool> visited(n, false);
    int timer = 0;
    vector<int> isArticulationPoint(n, false);

    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, tin, low, timer, -1, isArticulationPoint);
        }
    }

    return isArticulationPoint;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    inputGraph(adj, n, m);
    // printGraph(adj, n);
    vector<int> isArticulationPoint = articulationPoints(adj, n, m);
    for (int i=0; i<n; i++) {
        if (isArticulationPoint[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}