#include <iostream>
#include <vector>
#include <algorithm>    // std::sort

using namespace std;

void makeSet(vector<int> &parent, vector<int> &rank, int n) {
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(vector<int> &parent, int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent, parent[x]);
}

void unionSet(vector<int> &parent, vector<int> &rank, int x, int y) {
    int xRep = find(parent, x);
    int yRep = find(parent, y);

    if(rank[xRep] < rank[yRep]) {
        parent[xRep] = yRep;
    } else if(rank[xRep] > rank[yRep]) {
        parent[yRep] = xRep;
    } else {
        parent[yRep] = xRep;
        rank[xRep]++;
    }
}

int kruskal(vector<vector<int>> &edges, int n) {
    // Time Complexity: O(ElogE + ElogV)
    // Space Complexity: O(V)
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });

    int cost = 0;
    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(find(parent, u) != find(parent, v)) {
            cost += w;
            unionSet(parent, rank, u, v);
        }
    }

    return cost;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m);
    /*
    4 6
    0 1 3
    0 2 1
    0 3 2
    1 2 5
    1 3 2
    2 3 4
    Ans - 5
    */
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        edges[i] = {u, v, w};
    }

    cout << kruskal(edges, n) << endl;
}