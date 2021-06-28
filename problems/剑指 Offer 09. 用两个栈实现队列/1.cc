#include "..\..\leetcode.h"

class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {

        s1_.emplace(value);
    }
    
    int deleteHead() {

        if (s2_.empty()) {
            while (!s1_.empty()) {
                s2_.emplace(s1_.top()); s1_.pop();
            }
        }
        int res = -1;
        if (!s2_.empty()) {
            res = s2_.top(); s2_.pop();
        }
        return res;
    }

private:
    stack<int> s1_, s2_;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */