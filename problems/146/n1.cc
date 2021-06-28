#include "..\..\leetcode.h"

class LRUCache {
public:
    LRUCache(int capacity) : c_(capacity) {

    }
    
    int get(int key) {

        auto it = m_.find(key);
        if (it == m_.end()) return -1;

        l_.splice(l_.begin(), l_, it->second.second);
        return it->second.first;
    }
    
    void put(int key, int value) {

        auto it = m_.find(key);
        if (it != m_.end()) {
            it->second.first = value;
            l_.splice(l_.begin(), l_, it->second.second);
            return;
        }

        if (m_.size() == c_) {
            m_.erase(l_.back());
            l_.pop_back();
        }

        l_.emplace_front(key);
        m_[key] = {value, l_.begin()};
    }

private:
    int c_;
    unordered_map<int, pair<int, list<int>::iterator>> m_;
    list<int> l_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */