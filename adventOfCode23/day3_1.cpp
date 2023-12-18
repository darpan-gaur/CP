#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<string> input;

bool check(int colS, int colE, int row) {
    // colS :- n start, colE :- n end +1 
    for (int i=colS-1;i<=colE;i++) {
        if (i<0 || i>=input[row].length()) continue;
        for (int j=row-1;j<=row+1;j++) {
            if (j<0 || j>=input.size()) continue;
            // if input[j][i] not a number and not a dot return true
            if (input[j][i]!='.' && (input[j][i]<'0' || input[j][i]>'9')) return true;
        }
    }
    return false;
}

int main() {
    string inp;
    ll sPartNum=0;
    while (cin >> inp) {
        input.push_back(inp);
    }
    for (int row=0;row<input.size();row++) {
        for (int col=0;col<input[row].length();col++) {
            // get number if any
            ll num=0, ndig=0;
            if (input[row][col]>='0' && input[row][col]<='9') {
                // if number is found
                for (int i=col;i<input[row].length();i++) {
                    if (input[row][i]>='0' && input[row][i]<='9') {
                        num = num*10 + (input[row][i]-'0');
                        ndig++;
                    } else {
                        if (check(i-ndig,i,row)) {
                            cout << num << endl;
                            sPartNum += num;
                        }
                        col = i-1;
                        ndig=0;
                        break;
                    }
                }
                if (ndig!=0) {
                    if (check(col-ndig,col,row)) {
                        cout << num << endl;
                        sPartNum += num;
                    }
                    col += ndig-1;
                }
            }
        }
    }
    cout << sPartNum << endl;
    return 0;
}