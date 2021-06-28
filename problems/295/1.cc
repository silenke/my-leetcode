#include "..\..\leetcode.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {

        maxpq.emplace(num);

        minpq.emplace(maxpq.top());
        maxpq.pop();

        if (minpq.size() > maxpq.size()) {
            maxpq.emplace(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {

        if (maxpq.size() > minpq.size()) return maxpq.top();
        return (maxpq.top() + minpq.top()) * 0.5;
    }

private:
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */