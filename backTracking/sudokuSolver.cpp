/*
https://leetcode.com/problems/sudoku-solver/
*/

// Solution 1: Backtracking 
class Solution {
public:
    bool isSafe(int i, int j, char val, vector<vector<char>>& board) {
        int idx , n=board.size();
        for (idx=0;idx<n;idx++){
            // row
            if (board[i][idx]==val) return false;
            //col
            if (board[idx][j]==val) return false;
            // block
            if (board[3*(i/3)+idx/3][3*(j/3)+idx%3] == val) return false;
        }
        return true;

    }
    bool solve(vector<vector<char>>& board) {
        int n = board.size(), i, j;
        for (i=0;i<n;i++) {
            for (j=0;j<n;j++) {
                if (board[i][j]=='.') {
                    for (char ch = '1';ch<='9';ch++) {
                        if (!(isSafe(i, j, ch, board))) continue;
                        board[i][j] = ch;
                        bool validSol = solve(board);
                        if (validSol) return true;
                        else board[i][j] = '.'; 
                    }
                    return false;
                }

            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};