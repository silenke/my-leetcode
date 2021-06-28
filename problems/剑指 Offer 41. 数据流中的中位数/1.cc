#include "..\..\leetcode.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {

        mins.emplace(num);
        maxs.emplace(mins.top()); mins.pop();
        if (maxs.size() - mins.size() > 1) {
            mins.emplace(maxs.top()); maxs.pop();
        }
    }
    
    double findMedian() {

        if (maxs.size() > mins.size()) return maxs.top();
        return (maxs.top() + mins.top()) * 0.5;
    }

private:
    priority_queue<int> mins;
    priority_queue<int, vector<int>, greater<int>> maxs;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */