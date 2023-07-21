/*
https://practice.geeksforgeeks.org/problems/scrambled-string/1
*/

#include <iostream>

using namespace std;

// recursive
int recursive(string a, string b) {
    if (a.compare(b) == 0) {
        return 1;
    }
    if (a.length() <= 1) {
        return 0;
    }

    int n = a.length();
    bool flag = false;
    for (int i = 1; i < n; i++) {
        // swap
        if (recursive(a.substr(0, i), b.substr(n - i, i)) && recursive(a.substr(i, n - i), b.substr(0, n - i))) {
            flag = true;
            break;
        }
        // no swap
        if (recursive(a.substr(0, i), b.substr(0, i)) && recursive(a.substr(i, n - i), b.substr(i, n - i))) {
            flag = true;
            break;
        }
    }
    return flag;
}

int main() {
    string a, b;
    cin >> a >> b;
    /*
    great rgeat :- true
    phqtrnilf ilthnqrpf :- false
    */

    cout << recursive(a, b) << endl;

    return 0;
}