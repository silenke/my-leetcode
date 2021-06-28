#include "..\..\leetcode.h"

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {

        s.emplace((long long)x - m);
        m = min(m, x);
    }
    
    void pop() {

        if (s.top() < 0) m -= s.top();
        s.pop();
    }
    
    int top() {

        if (s.top() < 0) return m;
        return s.top() + m;
    }
    
    int getMin() {

        return m;
    }

private:
    stack<long long> s;
    int m = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */