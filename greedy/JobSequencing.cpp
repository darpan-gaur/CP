/*
https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

Solution 1 : Time :- O(nlogn) , Space :- O(n) using priority queue
Solution 2 : Time :- O(n^2) , Space :- O(n) 
*/

#include<bits/stdc++.h>
using namespace std; 

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

// O(nlogn) solution
class Solution 
{
    public:
    static bool comp_dead(Job a, Job b){
        return a.dead < b.dead;
    }
    static bool comp_profit(int a, int b){
        return a < b;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // sort jobs based on deadline 
        sort(arr, arr+n, comp_dead);
        
        priority_queue<int> pq;
        
        int i,ans=0,ansProfit=0,slots;
        for (i=n-1;i>=0;i--) {
            if (i) slots = arr[i].dead - arr[i-1].dead;
            else slots = arr[i].dead;
            
            pq.push(arr[i].profit);
            while (slots > 0 && pq.size() > 0) {
                int cp = pq.top();
                pq.pop();
                
                slots--;
                
                ans++;
                ansProfit += cp;
            }
        }
        return {ans,ansProfit};
    } 
};

// O(n^2) solution 
class Solution
{
    public:
    static bool comp(Job a, Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comp);
        int dead_n=0,i,ans=0,ansProfit=0,j;
        
        for (i=0;i<n;i++) dead_n = max(dead_n,arr[i].dead);
        vector<int> v(dead_n+1,-1);
        
        for (i=0;i<n;i++) {
            for (j=arr[i].dead;j>0;j--) {
                if (v[j]==-1) {
                    ansProfit += arr[i].profit;
                    ans++;
                    v[j] = arr[i].id;
                    break;
                }
            }
        }
        return {ans,ansProfit};
    } 
};

int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}