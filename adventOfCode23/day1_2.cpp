#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    // take input untill EOF
    string input;
    ll sCalVal = 0;
    vector<string> v = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while (cin >> input) {
        int dig=-1;
        for (int i=0;i<input.size();i++) {
            if (input[i]>='0' && input[i]<='9') {
                if (dig==-1) {
                    sCalVal += 10*(input[i]-'0');
                }
                dig = input[i]-'0';
            }
            else {
                for (int j=0;j<v.size();j++) {
                    if (input.substr(i, v[j].size())==v[j]) {
                        if (dig==-1) {
                            sCalVal += 10*(j+1);
                        }
                        dig = j+1;
                        break;
                    }
                }
            }
        }
        sCalVal += dig;
    }
    cout << sCalVal << endl;
    return 0;
}