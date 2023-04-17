/*
https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

Time Complexity: O(N*W)
Space Complexity: O(N*W)
*/


#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int i,j;
        int arr[n+1][W+1];
        memset(arr,-1,sizeof(arr));
        for (i=0;i<n+1;i++) arr[i][0] = 0;
        for (j=0;j<W+1;j++) arr[0][j] = 0;
        for (i=1;i<=n;i++) {
            for (j=1;j<=W;j++) {
                if (wt[i-1]<=j) {
                    arr[i][j] = max(val[i-1]+arr[i-1][j-wt[i-1]], arr[i-1][j]);
                }
                else arr[i][j] = arr[i-1][j];
            }
        }
        return arr[n][W];
    }
};


int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}