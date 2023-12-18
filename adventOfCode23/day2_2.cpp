#include <bits/stdc++.h>
#define ll long long

using namespace std;

/*
INput:
Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green
*/

int main() {
    ifstream inputFile("input.txt");
    if (inputFile.is_open()) {
        string line;
        ll sPower = 0;
        while (getline(inputFile, line)) {
            // get game id
            ll gameId = 0;
            int i;
            ll b = 0, r = 0, g = 0;
            for (i = 5; i < line.length(); i++) {
                if (line[i] == ':') {
                    break;
                }
                gameId = gameId * 10 + (line[i] - '0');
            }
            // get number of blue, red, green for each subgame separated by ';'
            ll sBlue = 0, sRed = 0, sGreen = 0, n = line.length();
            for (i=i+1; i < n; i++) {
                if (line[i]==' ' || line[i] == ',') continue;
                // cout << line[i] << endl;
                if (line[i] == ';') {
                    b = max(b, sBlue);
                    r = max(r, sRed);
                    g = max(g, sGreen);
                    sBlue = 0;
                    sRed = 0;
                    sGreen = 0;
                    continue;
                } 
                // get number
                ll number = 0;
                // cout << line[i] << endl;
                for (i; i < n; i++) {
                    if (line[i] == ' ') {
                        i++;
                        break;
                    }
                    number = number * 10 + (line[i] - '0');
                }
                // cout << number << endl;
                if (i == n) break;
                // get color
                char color = line[i];
                if (color == 'b') {
                    sBlue += number;
                    i+=3;
                } else if (color == 'r') {
                    sRed += number;
                    i+=2;
                } else {
                    sGreen += number;
                    i+=4;
                }
                
                // i--;
            }
            b = max(b, sBlue);
            r = max(r, sRed);
            g = max(g, sGreen);
            sPower += b*r*g;
            // cout << "\n";
        }
        inputFile.close();
        cout << sPower << endl;
    }
    return 0;
}