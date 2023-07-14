#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>   
class graph {
    public:
        unordered_map<T, vector<T>> adjList;
    void addEdge(T u, T v, bool directed = false) {
        // directed = false means undirected graph
        // directed = true means directed graph

        adjList[u].push_back(v);
        if (!directed) adjList[v].push_back(u);
    }

    void printAdjList() {
        for (auto node : adjList) {
            cout << node.first << " -> ";
            for (auto neighbour : node.second) {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    graph<int> g;

    for (int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.printAdjList();
}