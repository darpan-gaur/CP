#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    vector<string> input;
    string inp;
    while (cin >> inp) {
        input.push_back(inp);
    }
    
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    set<vector<int>> visited;
    vector<int> nInfo(6, 0);
    pq.push(nInfo);
    vector<pair<int,int>> neigh = {{0, 1}, {1,0}, {0, -1}, {-1, 0}};
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int heatLoss = top[0];
        int i = top[1], j = top[2], di = top[3], dj = top[4], steps = top[5];
        if (i == input.size() - 1 && j == input[0].size() - 1) {
            cout << heatLoss << endl;
            break;
        }
        if (visited.find({top[1], top[2], top[3], top[4], top[5]}) != visited.end()) {
            continue;
        }
        visited.insert({top[1], top[2], top[3], top[4], top[5]});
        if (steps < 3 && (di!=0 || dj!=0)) {
            if (i + di >= 0 && i + di < input.size() && j + dj >= 0 && j + dj < input[0].size()) {
                nInfo = {heatLoss+ (input[i + di][j + dj] - '0'), i + di, j + dj, di, dj, steps + 1};
                pq.push(nInfo);
            }   
        }
        for (auto n : neigh) {
            if ((n.first != di || n.second != dj) && (n.first != -di || n.second != -dj)) {
                if ((i + n.first >= 0 )&& (i + n.first < input.size()) && (j + n.second >= 0) && (j + n.second < input[0].size())) {
                    nInfo = {heatLoss+ (input[i + n.first][j + n.second] - '0'), i + n.first, j + n.second, n.first, n.second, 1};
                    pq.push(nInfo);
                }
            }
        }
    }
    return 0;
}