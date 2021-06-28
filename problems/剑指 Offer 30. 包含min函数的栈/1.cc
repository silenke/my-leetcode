#include "..\..\leetcode.h"

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

        mins_.emplace(INT_MAX);
    }
    
    void push(int x) {

        datas_.emplace(x);
        mins_.emplace(::min(mins_.top(), x));
    }
    
    void pop() {

        datas_.pop();
        mins_.pop();
    }
    
    int top() {

        return datas_.top();
    }
    
    int min() {

        return mins_.top();
    }

private:
    stack<int> datas_;
    stack<int> mins_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */