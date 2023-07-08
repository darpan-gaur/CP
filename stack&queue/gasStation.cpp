/*
https://leetcode.com/problems/gas-station/
*/

// Solution: 1
// Time: O(n), Space: O(1)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int reqGas = 0, currGas=0, start = 0, i, n = gas.size();
        
        for (i=0;i<n;i++) {
            currGas += gas[i] - cost[i];
            if (currGas < 0) {
                reqGas += currGas;
                start = i+1;
                currGas = 0;
            }
        }
        if (currGas + reqGas >= 0) return start;
        return -1;
    }
};