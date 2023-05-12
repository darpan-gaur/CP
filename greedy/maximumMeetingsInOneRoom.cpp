/*
https://practice.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

Time Complexity: O(NlogN)
Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<vector<int>> v(N);
        vector<int> ans;
        int i,temp;
        for (i=0;i<N;i++) v[i] = {F[i],S[i],i+1};
        sort(v.begin(),v.end());
        temp = v[0][0];
        ans.push_back(v[0][2]);
        for (i=1;i<N;i++) {
            if (v[i][1] > temp) {
                ans.push_back(v[i][2]);
                temp = v[i][0];
            } 
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}