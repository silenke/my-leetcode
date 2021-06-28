#include "..\..\leetcode.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

        set.insert(INT_MIN);
        set.insert(INT_MAX);
        mid = set.begin();
    }
    
    void addNum(int num) {

        set.insert(num);
        if (set.size() & 1 && num >= *mid) ++mid;
        if (!(set.size() & 1) && num < *mid) ++mid;
    }
    
    double findMedian() {

        if (set.size() & 1) return *mid;
        return (*mid + *next(mid)) * 0.5;
    }

private:
    multiset<int> set;
    multiset<int>::iterator mid;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */