// kmp algorithm c++

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getLPS(string pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    int i = 1, j = 0;   // j = prevLPS
    while (i < n) {
        if (pattern[i] == pattern[j]) {
            lps[i] = j + 1;
            i++;
            j++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int kmp(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = getLPS(pattern);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    if (j == m) {
        return i - j;
    }
    return -1;
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "ababd";
    cout << kmp(text, pattern) << endl;
    return 0;
}