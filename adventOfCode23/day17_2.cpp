#include <bits/stdc++.h>
#define ll long long

using namespace std;

class node {
    public:
    int heatLoss;
    int i, j;
    int di, dj;
    int steps;
    bool operator > (const node& n) const {
        return heatLoss > n.heatLoss;
    }
    bool operator < (const node& n) const {
        return heatLoss < n.heatLoss;
    }
};

int main() {
    vector<string> input;
    string inp;
    while (cin >> inp) {
        input.push_back(inp);
    }
    
    priority_queue<node, vector<node>, greater<node>> pq;
    set<tuple<int, int, int, int, int>> visited;
    pq.push({0, 0, 0, 0, 0, 0});
    vector<pair<int,int>> neigh = {{0, 1}, {1,0}, {0, -1}, {-1, 0}};
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int heatLoss = top.heatLoss;
        int i = top.i, j = top.j, di = top.di, dj = top.dj, steps = top.steps;
        if (i == input.size() - 1 && j == input[0].size() - 1 && steps > 3) {
            cout << heatLoss << endl;
            break;
        }
        if (visited.count({top.i, top.j, top.di, top.dj, top.steps})) {
            continue;
        }
        visited.insert({top.i, top.j, top.di, top.dj, top.steps});
        if (steps < 10 && (di!=0 || dj!=0)) {
            if ((i + di >= 0 && i + di < input.size()) && (j + dj >= 0 && j + dj < input[0].size())) {
                pq.push({heatLoss+ (input[i + di][j + dj] - '0'), i + di, j + dj, di, dj, steps + 1});
            }   
        }
        if (steps > 3 || (di == 0 && dj == 0)) {
            for (const auto& n: vector<pair<int,int>>{{0, 1}, {1,0}, {0, -1}, {-1, 0}}) {
                if ((n.first != di || n.second != dj) && (n.first != -di || n.second != -dj)) {  
                    if ((i + n.first >= 0 )&& (i + n.first < input.size()) && (j + n.second >= 0) && (j + n.second < input[0].size())) {
                        pq.push({heatLoss+ (input[i + n.first][j + n.second] - '0'), i + n.first, j + n.second, n.first, n.second, 1});
                    }
                }
            }
        }
    }
    return 0;
}