#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>    // std::reverse

using namespace std;

void inputGraph(vector<int> adj[], int n, int m) {
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
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

vector<int> shortestPathBFS(vector<int> adj[], int n, int src, int dest) {
    vector<int> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (auto u: adj[s]) {
            if (!visited[u]) {
                visited[u] = true;
                parent[u] = s;
                q.push(u);
            }
        }
    }

    // prepare shortest path
    vector<int> ans;
    int curr = dest;
    while (curr != -1) {
        ans.push_back(curr);
        curr = parent[curr];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    /*
    8 9
    1 2
    1 3
    1 4
    2 5
    5 8 
    3 8
    4 6
    6 7
    7 8
    // src -> dest
    1 8
    */
    inputGraph(adj, n, m);

    printGraph(adj, n);

    int src, dest;
    cin >> src >> dest;
    src--; dest--;
    vector<int> ans = shortestPathBFS(adj, n, src, dest);
    cout << "Shortest path from " << src+1 << " to " << dest+1 << " is: ";
    for (auto u: ans) {
        cout << u+1 << " ";
    }
    cout << "\n";

    return 0;
}