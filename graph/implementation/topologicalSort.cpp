/*
Topological Sort -> Directed Acyclic Graph (DAG)
    - Topological Sort is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering.
*/

#include <iostream>
#include <vector>
#include <stack>
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

void topoSort(int s, vector<bool>& visited, stack<int>& st, vector<int> adj[]) {
    visited[s] = true;
    for (auto u: adj[s]) {
        if (!visited[u]) {
            topoSort(u, visited, st, adj);
        }
    }
    st.push(s);
}

vector<int> topologicalSort(vector<int> adj[], int n) {
    vector<bool> visited(n, false);
    stack<int> st;
    for (int i=0;i<n;i++) {
        if (!visited[i]) {
            topoSort(i, visited, st, adj);
        }
    }
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

vector<int> kahnAlgo(vector<int> adj[], int n) {
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
    vector<int> ans;
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        ans.push_back(s);
        for (auto u: adj[s]) {
            inDegree[u]--;
            if (inDegree[u] == 0) {
                q.push(u);
            }
        }
    }
    return ans;
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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    /*
    5 6
    1 2
    1 3
    2 3
    2 4
    3 4
    4 5
    */
    inputGraph(adj, n, m);

    printGraph(adj, n);

    vector<int> ans = topologicalSort(adj, n);
    cout << "Topological Sort: ";
    for (auto u: ans) {
        cout << u+1 << " ";
    }
    cout << "\n";

    return 0;
}