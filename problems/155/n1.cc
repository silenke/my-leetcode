#include "..\..\leetcode.h"

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

        mins.emplace(INT_MAX);
    }
    
    void push(int x) {

        nums.emplace(x);
        mins.emplace(min(x, mins.top()));
    }
    
    void pop() {

        nums.pop();
        mins.pop();
    }
    
    int top() {

        return nums.top();
    }
    
    int getMin() {

        return mins.top();
    }

private:
    stack<int> nums;
    stack<int> mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */