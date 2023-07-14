/*
https://leetcode.com/problems/find-median-from-data-stream
*/

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// Solution 1: use two heaps
class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n1, n2;
    double median;
    MedianFinder() {
        median = INT_MIN;
    }
    
    void addNum(int num) {
        n1 = maxHeap.size();
        n2 = minHeap.size();
        if (n1==n2) {
            if (num > median) {
                minHeap.push(num);
                median = minHeap.top();
            }
            else {
                maxHeap.push(num);
                median = maxHeap.top();
            }
        }
        // maxHeap > minHeap
        else if (n1 > n2) {
            if (num > median) {
                minHeap.push(num);
            }
            else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
            median = (double)(minHeap.top() + maxHeap.top())/2;
        }
        // minHeap > maxHeap
        else {
            if (num > median) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            else {
                maxHeap.push(num);
            }
            median = (double)(minHeap.top() + maxHeap.top())/2;
        }
    }
    
    double findMedian() {
        return median;
    }
};

// Solution 2: use two heaps
class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(maxHeap.size()==0 || maxHeap.top() > num) maxHeap.push(num);
        else minHeap.push(num);

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if ((minHeap.size()+maxHeap.size())%2==0) {
            return (double)(minHeap.top() + maxHeap.top())/2;
        }
        else if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        else return minHeap.top();
    }
};