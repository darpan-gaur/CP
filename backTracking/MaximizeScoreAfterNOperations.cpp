/*
Link : - https://leetcode.com/problems/maximize-score-after-n-operations/
*/

// Solution 1 , DP + bitmasking (recursion)
// Time complexity = O(4^n * n^2 * logA) (where A max value in nums), Space complexity = O(n + 2^(2n))
class Solution {
public:
    int backtrack(vector<int>& nums, int mask, int pairsPicked, vector<int>& memo) {
        // If we have picked all the numbers from 'nums' array, we can't get more score.
        if (2 * pairsPicked == nums.size()) {
            return 0;
        }

        // If we already solved this sub-problem then return the stored result.
        if (memo[mask] != -1) {
            return memo[mask];
        }

        int maxScore = 0;

        // Iterate on 'nums' array to pick the first and second number of the pair.
        for (int firstIndex = 0; firstIndex < nums.size(); ++firstIndex) {
            for (int secondIndex = firstIndex + 1; secondIndex < nums.size(); ++secondIndex) {
    
                // If the numbers are same, or already picked, then we move to next number.
                if (((mask >> firstIndex) & 1) == 1 or ((mask >> secondIndex) & 1) == 1) {
                    continue;
                }

                // Both numbers are marked as picked in this new mask.
                int newMask = mask | (1 << firstIndex) | ((1 << secondIndex));

                // Calculate score of current pair of numbers, and the remaining array.
                int currScore = (pairsPicked + 1) * __gcd(nums[firstIndex], nums[secondIndex]);
                int remainingScore = backtrack(nums, newMask, pairsPicked + 1, memo);

                // Store the maximum score.
                maxScore = max(maxScore, currScore + remainingScore);
                // We will use old mask in loop's next interation, 
                // means we discarded the picked number and backtracked.
            }
        }

        // Store the result of the current sub-problem.
        memo[mask] = maxScore;
        return maxScore;
    }

    int maxScore(vector<int>& nums) {
        int memoSize = 1 << nums.size(); // 2^(nums array size)
        vector<int> memo(memoSize, -1);
        return backtrack(nums, 0, 0, memo);
    }
};

// Solution 2 , DP + bitmasking (iterative)
// Time complexity = O(4^n * n^2 * logA) (where A max value in nums), Space complexity = O(2^(2n))
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int maxStates = 1 << nums.size(); // 2^(nums array size)
        int finalMask = maxStates - 1;

        // 'dp[i]' stores max score we can get after picking remaining numbers represented by 'i'.
        vector<int> dp(maxStates);

        // Iterate on all possible states one-by-one.
        for (int state = finalMask; state >= 0; state -= 1) {
            // If we have picked all numbers, we know we can't get more score as no number is remaining.
            if (state == finalMask) {
                dp[state] = 0;
                continue;
            }

            int numbersTaken = __builtin_popcount(state);
            int pairsFormed = numbersTaken / 2;
            // States representing even numbers are taken are only valid.
            if (numbersTaken % 2) {
                continue;
            }

            // We have picked 'pairsFormed' pairs, we try all combinations of one more pair now.
            // We itearte on two numbers using two nested for loops.
            for (int firstIndex = 0; firstIndex < nums.size(); firstIndex += 1) {
                for (int secondIndex = firstIndex + 1; secondIndex < nums.size(); secondIndex += 1) {
                    // We only choose those numbers which were not already picked.
                    if (((state >> firstIndex) & 1) == 1 || ((state >> secondIndex) & 1) == 1) {
                        continue;
                    }
                    int currentScore = (pairsFormed + 1) * __gcd(nums[firstIndex], nums[secondIndex]);
                    int stateAfterPickingCurrPair = state | (1 << firstIndex) | (1 << secondIndex);
                    int remainingScore = dp[stateAfterPickingCurrPair];
                    dp[state] = max(dp[state], currentScore + remainingScore);
                }
            }
        }

        // Returning score we get from 'n' remaining numbers of array.
        return dp[0];
    }
};