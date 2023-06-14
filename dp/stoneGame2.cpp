/*
https://leetcode.com/problems/stone-game-ii/
*/

// Time :- O(n^3), Space :- O(n^2)
class Solution {
public:
    int alice[101][202], bob[101][202];
    int solve(int idx, int m, int chance, vector<int>& piles) {
        if (idx >= piles.size()) return 0;
        if (chance) if (alice[idx][m]!=-1) return alice[idx][m];
        if (!chance) if (bob[idx][m]!=-1) return bob[idx][m];
        int ans=0,i,sum=0;
        if (!chance) ans = INT_MAX;
        for (i=0;(i<2*m)&&(idx+i<piles.size());i++) {
            sum += piles[idx+i];
            if (chance) ans = max(ans, sum + solve(idx+i+1, max(m, i+1), !chance, piles));
            else ans = min(ans, solve(idx+i+1, max(m, i+1), !chance, piles));
        }
        if (chance) return alice[idx][m] = ans;
        return bob[idx][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(alice, -1, sizeof(alice));
        memset(bob, -1, sizeof(bob));
        return solve(0,1,1,piles);
    }
};