#include "..\..\leetcode.h"

class LFUCache {
public:
    LFUCache(int capacity) : c_(capacity), min_(0) {

    }
    
    int get(int key) {

        auto it = m_.find(key);
        if (it == m_.end()) return -1;

        touch(it->second.second);
        return it->second.first;
    }
    
    void put(int key, int value) {

        if (c_ == 0) return;

        auto it = m_.find(key);
        if (it != m_.end()) {
            touch(it->second.second);
            it->second.first = value;
            return;
        }

        if (m_.size() == c_) {
            m_.erase(l_[min_].back().first);
            l_[min_].pop_back();
            if (l_[min_].empty() && min_ != 1) {
                l_.erase(min_);
            }
        }

        min_ = 1;
        l_[min_].emplace_front(key, min_);
        m_[key] = {value, l_[min_].begin()};
    }

private:
    int c_;
    int min_;
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> m_;
    unordered_map<int, list<pair<int, int>>> l_;

    void touch(list<pair<int, int>>::iterator it) {

        int prev = it->second;
        int curr = ++it->second;

        l_[curr].splice(l_[curr].begin(), l_[prev], it);

        if (l_[prev].empty()) {
            l_.erase(prev);
            if (min_ == prev) {
                min_++;
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */