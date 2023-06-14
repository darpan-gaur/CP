// implement dfs
#include <bits/stdc++.h>

using namespace std;

// input graph adjacency list
void inputGraph(vector<int> adj[], int n, int m) {
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
}

// Time complexity: O(V+E)
void dfs(int s, vector<int> adj[], bool visited[]) {
    if (visited[s]) return;
    visited[s] = true;
    // print
    cout << s+1 << " ";
    // process node s
    for (auto u: adj[s]) {
        dfs(u, adj, visited);
    }
}

// print aadjacency list
void printGraph(vector<int> adj[], int n) {
    for (int i=0; i<n; i++) {
        cout << i+1 << ": ";
        for (auto u: adj[i]) {
            cout << u+1 << " ";
        }
        cout << "\n";
    }
}

int main() {
    // input graph adjacency list
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    inputGraph(adj, n, m);

    // print graph
    printGraph(adj, n);

    // dfs
    bool visited[n];
    memset(visited, false, sizeof(visited));
    dfs(0, adj, visited);

    return 0;
}