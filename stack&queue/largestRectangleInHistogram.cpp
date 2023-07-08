/*
https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

// Solution 1
// Time O(n), Space O(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n=heights.size(),i,ans=0,tempAns;

        // next smaller index
        vector<int> nsi(n,0);
        stack<int> st;
        st.push(-1);
        for (i=n-1;i>=0;i--) {
            while (st.top()!=-1 && heights[i] <= heights[st.top()]) st.pop();
            nsi[i] = st.top();
            st.push(i);
        } 

        // prev smaller index
        vector<int> psi(n,0);
        st = stack<int> ();
        st.push(-1);
        for (i=0;i<n;i++) {
            while (st.top()!=-1 && heights[i] <= heights[st.top()]) st.pop();
            psi[i] = st.top();
            st.push(i);
        }

        for (i=0;i<n;i++) {
            if (nsi[i]==-1) nsi[i] = n;
            ans = max(ans, heights[i]*(nsi[i]-psi[i]-1));
        }

        return ans;
        
    }
};