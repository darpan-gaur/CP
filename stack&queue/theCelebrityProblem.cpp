/*
https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

Best:- Time O(n), Space O(1)
*/

// Solution 1
// Time O(n), Space O(n)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        stack<int> st;
        int i,c1,c2;
        for (i=0;i<n;i++) st.push(i);
        while (st.size()>1) {
            c1 = st.top(); st.pop();
            c2 = st.top(); st.pop();
            if (m[c1][c2]) st.push(c2);
            else st.push(c1);
        }
        
        c1 = st.top();
        for (i=0;i<n;i++) {
            if (m[c1][i]!=0) return -1;
            if (i!=c1 && m[i][c1]!=1) return -1;
        }
        return c1;
    }
};  

// Solution 2
// Time O(n), Space O(1)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        int i,c1,c2;
        c1 = 0;
        for (i=1;i<n;i++) {
            if (m[c1][i]) c1 = i;
        }
        
        for (i=0;i<n;i++) {
            if (m[c1][i]!=0) return -1;
            if (i!=c1 && m[i][c1]!=1) return -1;
        }
        return c1;
    }
};

