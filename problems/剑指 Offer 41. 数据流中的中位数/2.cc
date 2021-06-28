#include "..\..\leetcode.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

        tree.insert({INT_MIN, INT_MAX});
        tree.insert(INT_MAX);
        mid = tree.begin();
    }
    
    void addNum(int num) {

        tree.insert(num);
        if ((tree.size() & 1) && num >= *mid) mid++;
        else if (!(tree.size() & 1) && num < *mid) mid--;
    }
    
    double findMedian() {

        if (tree.size() & 1) return *mid;
        return (*mid + *next(mid)) * 0.5;
    }

private:
    multiset<int> tree;
    multiset<int>::iterator mid;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */