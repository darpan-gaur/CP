#include <iostream>
#include <string>
#define ll long long

using namespace std;

int main() {
    // take input untill EOF
    string input;
    ll sCalVal = 0;
    while (cin >> input) {
        int dig=-1;
        for (int i=0;i<input.size();i++) {
            if (input[i]>='0' && input[i]<='9') {
                if (dig==-1) {
                    sCalVal += 10*(input[i]-'0');
                }
                dig = input[i]-'0';
            }
        }
        sCalVal += dig;
    }
    cout << sCalVal << endl;
    return 0;
}