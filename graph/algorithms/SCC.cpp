#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// input graph
void inputGraph(vector<int> adj[], int n, int m) {
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        // u--; v--;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
}

// print
void print(vector<int> adj[], int n) {
    for (int i=0;i<n;i++) {
        cout << i << ": ";
        for (auto u: adj[i]) {
            cout << u << " ";
        }
        cout << endl;
    }
}

void topoSort(int s, vector<bool>& visited, stack<int>& st, vector<int> adj[]) {
    visited[s] = true;
    for (auto u: adj[s]) {
        if (!visited[u]) {
            topoSort(u, visited, st, adj);
        }
    }
    st.push(s);
}

void dfs(int s, vector<bool>& visited, vector<int> adj[]) {
    visited[s] = true;
    for (auto u: adj[s]) {
        if (!visited[u]) {
            dfs(u, visited, adj);
        }
    }
}

int SCC(vector<int> adj[], int n) {
    // topological sort
    vector<bool> visited(n, false);
    stack<int> st;
    for (int i=0;i<n;i++) {
        if (!visited[i]) {
            topoSort(i, visited, st, adj);
        }
    }

    // transpose graph
    vector<int> adjT[n];
    for (int i=0;i<n;i++) {
        for (auto u: adj[i]) {
            adjT[u].push_back(i);
        }
    }

    // DFS on transpose graph
    int ans = 0;
    visited.assign(n, false);
    while (!st.empty()) {
        int s = st.top();
        st.pop();
        if (!visited[s]) {
            ans++;
            dfs(s, visited, adjT);
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    inputGraph(adj, n, m);
    cout << SCC(adj, n) << endl;
    return 0;
}