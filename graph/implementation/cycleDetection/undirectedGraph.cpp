#include <iostream>
#include <vector>
#include <queue>
#include <cstring>  // memset

using namespace std;

// input graph adjacency list
void inputGraph(vector<int> adj[], int n, int m) {
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
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

// Undirected graph
bool isCycleBFS(vector<int> adj[], int s, vector<bool>& visited, int n) {
    queue<int> q;
    int parent[n];
    memset(parent, -1, sizeof(parent));
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // process node u
        for (auto v: adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            } else if (parent[u] != v) {
                return true;
            }
        }
    }
    return false;
}

bool isCycleDFS(vector<int> adj[], int s, vector<bool>& visited, int parent) {
    visited[s] = true;
    for (auto u: adj[s]) {
        if (!visited[u]) {
            if (isCycleDFS(adj, u, visited, s)) {
                return true;
            }
        } else if (u != parent) {
            return true;
        }
    }
    return false;
}

bool cycleDetection(vector<int> adj[], int n) {
    vector<bool> visited(n, false);
    for (int i=0;i<n;i++) {
        if (!visited[i]) {
            // if (isCycleBFS(adj, i, visited, n)) {
            //     return true;
            // }
            if (isCycleDFS(adj, i, visited, -1)) {
                return true;
            }
        }
    }
    return false;
}


int main() {
    // input graph adjacency list
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    /* input graph
    4 4
    1 2
    2 3
    3 4
    1 3
    */

    inputGraph(adj, n, m);

    // print graph
    printGraph(adj, n);

    // cycle detection -> bfs
    cout << "Cycle detected:- ";
    cout << cycleDetection(adj, n) << "\n";



    return 0;
}