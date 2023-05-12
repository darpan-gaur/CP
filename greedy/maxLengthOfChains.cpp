/*
https://practice.geeksforgeeks.org/problems/max-length-chain/1

Time Complexity: O(NlogN)
Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    int maxChainLen(struct val p[],int n){
        vector<pair<int,int>> v(n);
        int i,ans=1,temp;
        for (i=0;i<n;i++) {
            v[i].first = p[i].second;
            v[i].second = p[i].first;
        }
        sort(v.begin(),v.end());
        temp = v[0].first;
        for (i=1;i<n;i++) {
            if (v[i].second > temp) {
                ans += 1;
                temp = v[i].first;
            }
        }
        return ans;
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}