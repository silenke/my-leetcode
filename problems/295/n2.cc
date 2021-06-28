#include "..\..\leetcode.h"

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

        set.insert(INT_MIN);
        set.insert(INT_MAX);
        l = set.begin();
        r = next(l);
    }
    
    void addNum(int num) {

        auto it = set.insert(num);
        if (set.size() & 1) {
            if (num < *l) r = l;
            else if(num >= *r) l = r;
            else l = r =it;
        }
        else {
            if (num < *l) --l;
            else ++r;
        }
    }
    
    double findMedian() {

        return (*l + *r) * 0.5;
    }

private:
    multiset<int> set;
    multiset<int>::iterator l, r;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */