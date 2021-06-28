#include "..\..\leetcode.h"

class LFUCache {
public:
    LFUCache(int capacity) : capacity_(capacity), min_(0) {

    }
    
    int get(int key) {

        auto it = cache_.find(key);
        if (it == cache_.end()) return -1;

        touch(it->second.second);
        return it->second.first;
    }
    
    void put(int key, int value) {

        if (capacity_ == 0) return;

        auto it = cache_.find(key);
        if (it != cache_.end()) {
            it->second.first = value;
            touch(it->second.second);
            return;
        }

        if (cache_.size() == capacity_) {
            cache_.erase(lists_[min_].back().first);
            lists_[min_].pop_back();
            if (lists_[min_].empty() && min_ > 1) lists_.erase(min_);
        }

        min_ = 1;
        lists_[min_].emplace_front(key, min_);
        cache_[key] = {value, lists_[min_].begin()};
    }

private:
    int capacity_;
    int min_;
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache_;
    unordered_map<int, list<pair<int, int>>> lists_;
    
    void touch(list<pair<int, int>>::iterator& it) {

        int prev = it->second;
        int curr = ++it->second;

        lists_[curr].splice(lists_[curr].begin(), lists_[prev], it);

        if (lists_[prev].empty()) {
            lists_.erase(prev);
            if (min_ == prev) min_++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */