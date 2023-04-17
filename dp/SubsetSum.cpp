/*
https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

Time Complexity: O(N*sum)
Space Complexity: O(N*sum)
*/

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size(),i,j;
        vector<vector<bool>> v(n+1, vector<bool> (sum+1,0));
        for (i=0;i<=sum;i++) v[0][i] = 0;
        for (i=0;i<=n;i++) v[i][0] = 1;
        for (i=1;i<=n;i++) {
            for (j=1;j<=sum;j++) {
                if (arr[i-1]<=j) {
                    v[i][j] = (v[i-1][j-arr[i-1]])||(v[i-1][j]);
                }
                else v[i][j] = v[i-1][j];
            }
        }
        return v[n][sum];
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 