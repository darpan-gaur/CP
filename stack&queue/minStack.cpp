/*
https://leetcode.com/problems/min-stack/
*/


// Solution 1
// GetMin :- Time O(1), Space O(1)
class MinStack {
public:
    stack<long long> s;
    long long minEle; 
    MinStack() {
    
    }
    
    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minEle = val;
        }
        else {
            if (val < minEle) {
                s.push(2LL*val-minEle);
                minEle = val;
            }
            else s.push(val);
        }
    }
    
    void pop() {
        if (s.top() < minEle) {
            minEle = 2LL*minEle - s.top();
        }
        s.pop();
    }
    
    int top() {
        if (s.top() < minEle) {
            return minEle;
        }
        else {
            return s.top();
        }

    }
    
    int getMin() {
        return minEle;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

