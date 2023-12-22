#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    vector<string> input;
    string line;
    while (getline(cin, line)) {
        input.push_back(line);
    }
    // print input
    // for (auto i : input) {
    //     cout << i << endl;
    // }

    // (dx, dy) for dx in {-1,0,1} for dy in {-1,0,1} excluding (0,0)
    vector<pair<int, int>> adj;
    for (int dx=-1; dx<=1; dx++) {
        for (int dy=-1; dy<=1; dy++) {
            if (dx!=0 || dy!=0) {
                adj.push_back(make_pair(dx, dy));
            }
        }
    }
    ll res = 0;
    int m = input.size(), n = input[0].size();
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            char curr = input[i][j];
            if (curr != '*') continue;
            set<pair<int,int>> pos;
            for (auto p : adj) {
                int dx = p.first, dy = p.second;
                int x = i+dx, y = j+dy;
                if (x>=0 && x<m && y>=0 && y<n && (input[x][y]>='0' && input[x][y]<='9')) {
                    while (y>0 && (input[x][y-1]>='0' && input[x][y-1]<='9')) {
                        y--;
                    }
                    pos.insert({x, y});
                }
            }
            // cout << pos.size() << endl;
            if (pos.size()!=2) continue;
            ll t1=-1, t2=-1;
            for (auto p : pos) {
                int x = p.first, y = p.second;
                string num="";
                while (y<n && input[x][y]>='0' && input[x][y]<='9') {
                    num += input[x][y];
                    y++;
                }
                if (t1==-1) t1 = stoi(num);
                else t2 = stoi(num);
            }
            res += t1*t2;
        }
    }
    
    cout << res << endl;

    return 0;
}