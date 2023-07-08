/*
https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581
*/

// Solution 1
// Time Complexity: O(n), Space Complexity: O(n)
#include <stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(n,0);
    for (int i=n-1;i>=0;i--) {
        while (st.top() >= arr[i]) st.pop();
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}
