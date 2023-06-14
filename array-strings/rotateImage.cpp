/*
https://leetcode.com/problems/rotate-image/
*/

// Solution 1, Time Complexity: O(n^2), Space Complexity: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j,n=matrix.size(),temp;
        for (i=0;i<(n+1)/2;i++) {
            for (j=0;j<n/2;j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
    }
};

// Solution 2, Time Complexity: O(n^2), Space Complexity: O(1)
// Transpose and then reverse each row
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j,n=matrix.size();
        // transpose
        for (i=0;i<n;i++) {
            for (j=i+1;j<n;j++) swap(matrix[i][j],matrix[j][i]);
        }

        // reflect
        for (i=0;i<n;i++) {
            for (j=0;j<n/2;j++) swap(matrix[i][j], matrix[i][n-1-j]);
        }
    }
};
