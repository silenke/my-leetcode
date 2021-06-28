#include "..\..\leetcode.h"

class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {

        if (nums.empty()) return -1;
        return maxs.front();
    }
    
    void push_back(int value) {

        nums.push(value);
        while (!maxs.empty() && maxs.back() < value) {
            maxs.pop_back();
        }
        maxs.push_back(value);
    }
    
    int pop_front() {

        if (nums.empty()) return -1;
        int res = nums.front(); nums.pop();
        if (res == maxs.front()) maxs.pop_front();
        return res;
    }

private:
    queue<int> nums;
    deque<int> maxs;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */