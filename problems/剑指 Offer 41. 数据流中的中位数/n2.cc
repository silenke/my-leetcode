#include "..\..\leetcode.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

        tree_.insert(INT_MIN);
        mid_ = tree_.insert(INT_MAX);
    }
    
    void addNum(int num) {

        tree_.insert(num);
        if ((tree_.size() & 1) && num < *mid_) mid_--;
        else if (!(tree_.size() & 1) && num >= *mid_) mid_++;
    }
    
    double findMedian() {

        if (tree_.size() & 1) return *mid_;
        return (*mid_ + *prev(mid_)) * 0.5;
    }

private:
    multiset<int> tree_;
    multiset<int>::iterator mid_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */