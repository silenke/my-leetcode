#include "..\..\leetcode.h"

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() : m_(INT_MAX) {

    }
    
    void push(int x) {

        s_.emplace(static_cast<long>(x) - m_);
        m_ = ::min(m_, x);
    }
    
    void pop() {

        if (s_.top() < 0) m_ -= s_.top();
        s_.pop();
    }
    
    int top() {

        if (s_.top() < 0) return m_;
        return s_.top() + m_;
    }
    
    int min() {

        return m_;
    }

private:
    stack<long> s_;
    int m_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */