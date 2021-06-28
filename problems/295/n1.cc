#include "..\..\leetcode.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {

        maxq.emplace(num);
        minq.emplace(maxq.top()); maxq.pop();
        if (minq.size() > maxq.size()) {
            maxq.emplace(minq.top()); minq.pop();
        }
    }
    
    double findMedian() {
        
        if (maxq.size() > minq.size()) return maxq.top();
        return (minq.top() + maxq.top()) * 0.5;
    }

private:
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */