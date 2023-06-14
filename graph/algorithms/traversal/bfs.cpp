/*
Breadth-first search (BFS) visits the nodes in increasing order of their distance
from the starting node.
*/

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

// Time complexity: O(V+E)
void bfs(int s, vector<int> adj[]) {
    queue<int> q;
    bool visited[adj->size()];
    int dist[adj->size()];
    memset(visited, false, sizeof(visited));
    memset(dist, -1, sizeof(dist));
    visited[s] = true;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // print
        cout << u+1 << " ";
        // process node u
        for (auto v: adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
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

    // bfs
    bfs(0, adj);
    
    return 0;
}