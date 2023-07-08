/*
https://practice.geeksforgeeks.org/problems/max-rectangle/1
*/

// Use of largest rectangle in histogram

// Solution 1
// Time Complexity: O(n^2), Space Complexity: O(n)
class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int i,j,area=0,h;
        
        // calculate histogram height values for each row as base
        for (i=1;i<n;i++) {
            for (j=0;j<m;j++) if (M[i][j]) M[i][j] += M[i-1][j];
        }
        
        stack<int> st;
        // calculate max area for each row
        for (i=0;i<n;i++) {
            j=0;
            while (j<m) {
                if (st.empty() || M[i][st.top()] <= M[i][j]) st.push(j++);
                else {
                    h = st.top();
                    st.pop();
                    area = max(area, M[i][h]*(st.empty() ? j:j-st.top()-1));
                }
            }
            while (!st.empty()) {
                h = st.top();
                st.pop();
                area = max(area, M[i][h]*(st.empty() ? j:j-st.top()-1));
            }
        }
        return area;
    }
};