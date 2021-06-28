#include "..\..\leetcode.h"

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {

    }
    
    int get(int key) {

        auto it = cache_.find(key);
        if (it == cache_.end()) return -1;

        list_.splice(list_.begin(), list_, it->second.second);
        return it->second.first;
    }
    
    void put(int key, int value) {

        auto it = cache_.find(key);
        if (it != cache_.end()) {
            it->second.first = value;
            list_.splice(list_.begin(), list_, it->second.second);
            return;
        }

        if (cache_.size() == capacity_) {
            cache_.erase(list_.back());
            list_.pop_back();
        }

        list_.emplace_front(key);
        cache_[key] = {value, list_.begin()};
    }

private:
    int capacity_;
    unordered_map<int, pair<int, list<int>::iterator>> cache_;
    list<int> list_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int paracache_1 = obj->get(key);
 * obj->put(key,value);
 */