/*
https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
*/

// Solution: 1 
// Time: O(n), Space: O(1)
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        vector<long long> ans;
        long long int negIdx=0, negEle,i;
        for (i=K-1;i<N;i++) {
            while ((negIdx<i) && ((negIdx<=i-K) || (A[negIdx]>=0))) negIdx++;
            if (A[negIdx]<0) negEle = A[negIdx];
            else negEle = 0;
            ans.push_back(negEle);
        }
        return ans;
 }

// Solution: 2 Queue
// Time: O(n), Space: O(k)
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        vector<long long> ans(N-K+1);
        deque<long long int> dq;
        
        int i;
        for (i=0;i<K;i++) {
            if (A[i] < 0) dq.push_back(i);
        }
        
        i = 0;
        if (!dq.empty()) {
            ans[i] = A[dq.front()];
        }else ans[i] = 0;
        
        for (i=K;i<N;i++) {
            if (!dq.empty() && i-dq.front()>=K) {
                dq.pop_front();
            }
            
            if (A[i]<0) dq.push_back(i);
            
            if (!dq.empty()) {
                ans[i-K+1] = A[dq.front()];
            }else ans[i-K+1] = 0;
            
        }
        return ans;
                                                 
 }