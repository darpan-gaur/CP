#include<bits/stdc++.h>
using namespace std;

const int N = 100005, M = 1000000007;

int mul(long long x, long long y) {
    return x * y % M;
}

int pow(int x, int y) {
    int r = 1;
    for (; y; y >>= 1) {
        if (y & 1) {
            r = mul(r, x);
        }
        x = mul(x, x);
    }
    return r;
}

int rev(int x) {
    return pow(x, M - 2);
}
        
int C(const vector<int> &f, const vector<int> &rf, int x, int y) {
    return mul(mul(f[x], rf[y]), rf[x - y]);
}

int main() {
    int z;
    vector<int> f(N), rf(N);
    for (int i = f[0] = rf[0] = 1; i < N; ++i) {
        f[i] = mul(f[i - 1], i);
        rf[i] =rev(f[i]);
        assert(mul(f[i], rf[i]) == 1);
    }
    for (cin >> z; z; --z) {
        int n, m;
        string s;
        cin >> n >> m >> s;
        // unordered_map<char, int> have;
        // for (char c : s) {
        //     ++have[c];
        // }
        // map<int, int> count;
        // for (const auto& p : have) {
        //     ++count[p.second];
        // }
        // int r = 1;
        // for (auto t = count.rbegin(); m && t != count.rend(); ++t) {
        //     const int temp = min(m, t->second);
        //     r = mul(r, mul(pow(t->first, temp), C(f, rf, t->second, temp)));
        //     m -= temp;
        // }
        // cout << (m ? 0 : r) << endl;
        cout << C(f, rf, 5, 2) << "\n";
    }
    return 0;
}