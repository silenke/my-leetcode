#include "..\..\leetcode.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {

        mins_.emplace(num);
        maxs_.emplace(mins_.top()); mins_.pop();
        if (maxs_.size() - mins_.size() > 1) {
            mins_.emplace(maxs_.top()); maxs_.pop();
        }
    }
    
    double findMedian() {

        if (maxs_.size() > mins_.size()) return maxs_.top();
        return (mins_.top() + maxs_.top()) * 0.5;
    }

private:
    priority_queue<int> mins_;
    priority_queue<int, vector<int>, greater<int>> maxs_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */