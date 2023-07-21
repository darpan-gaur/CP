#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void inputGraph(vector<int> adj[], int n, int m) {
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
}

void printGraph(vector<int> adj[], int n) {
    for (int i=0; i<n; i++) {
        cout << i+1 << ": ";
        for (auto u: adj[i]) {
            cout << u+1 << " ";
        }
        cout << "\n";
    }
}

bool isCycleDFS(vector<int> adj[], int s, vector<bool>& visited, vector<bool>& dfsVisited) {
    visited[s] = true;
    dfsVisited[s] = true;
    for (auto u: adj[s]) {
        if (!visited[u]) {
            if (isCycleDFS(adj, u, visited, dfsVisited)) {
                return true;
            }
        } else if (dfsVisited[u]) {
            return true;
        }
    }
    dfsVisited[s] = false;
    return false;
}

bool detectCycle(vector<int> adj[], int n) {
    vector<bool> visited(n, false);
    vector<bool> dfsVisited(n, false);
    for (int i=0;i<n;i++) {
        if (!visited[i]) {
            if (isCycleDFS(adj, i, visited, dfsVisited)) {
                return true;
            }
        }
    }
    return false;
}

bool detectCycleBFS(vector<int> adj[], int n) {
    vector<int> inDegree(n, 0);
    for (int i=0;i<n;i++) {
        for (auto u: adj[i]) {
            inDegree[u]++;
        }
    }
    queue<int> q;
    for (int i=0;i<n;i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        count++;
        for (auto u: adj[s]) {
            inDegree[u]--;
            if (inDegree[u] == 0) {
                q.push(u);
            }
        }
    }
    return count != n;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    /*
    5 6
    1 2
    4 1
    2 4
    3 4
    5 2
    1 3
    */
    inputGraph(adj, n, m);

    printGraph(adj, n);

    cout << detectCycle(adj, n) << "\n";
    cout << detectCycleBFS(adj, n) << "\n";

    return 0;
}