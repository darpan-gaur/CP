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
    bool flag = false;
    int m = input.size(), n = input[0].size();
    string num="";
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            char curr = input[i][j];
            // if curr is digit
            if (curr >= '0' && curr <= '9') {
                // if any input[i+dx][j+dy] is digit
                if (any_of(adj.begin(), adj.end(), [&](pair<int, int> p) {
                    int dx = p.first, dy = p.second;
                    int x = i+dx, y = j+dy;
                    return (x>=0 && x<m && y>=0 && y<n && (input[x][y]!='.') && (input[x][y]<'0' || input[x][y]>'9'));
                })) {
                    flag = true;
                }
                num += curr;
            }
            else {
                if (flag && num!="") {
                    res += stoi(num);
                }
                num = "";
                flag = false;
            }
        }
        if (flag && num!="") {
            res += stoi(num);
        }
        num = "";
        flag = false;
    }
    
    cout << res << endl;

    return 0;
}