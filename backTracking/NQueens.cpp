/*
https://leetcode.com/problems/n-queens/submissions/912800334/

Time Complexity :- O(n!)
*/


class Solution {
public:
    vector<int> col,diagM,diagNM;
    vector<vector<string>> ans;vector<string> inter;
    void NQueen(int j,int n){
        if (j==n) {
            ans.push_back(inter);
            return;
        }
        for (int i=0;i<n;i++) {
            if (col[i]||diagM[i+j]||diagNM[i-j+n-1]) continue;
            inter[i][j] = 'Q';
            col[i] = diagM[i+j] = diagNM[i-j+n-1] = 1;
            NQueen(j+1,n);
            inter[i][j] = '.';
            col[i] = diagM[i+j] = diagNM[i-j+n-1] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int i;
        for (i=0;i<n;i++) col.push_back(0);
        for (i=0;i<2*n-1;i++) {
            diagM.push_back(0);
            diagNM.push_back(0);
        }
        string s;
        for (i=0;i<n;i++) s+= '.';
        for (i=0;i<n;i++) inter.push_back(s);
        NQueen(0,n);
        return ans;
    }
};