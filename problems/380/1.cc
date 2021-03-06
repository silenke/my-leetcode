#include "..\..\leetcode.h"

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {

        if (map.find(val) != map.end()) return false;
        
        nums.emplace_back(val);
        map[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {

        auto it = map.find(val);
        if (it == map.end()) return false;

        int back = nums.back();
        nums[it->second] = back;
        nums.pop_back();
        
        map[back] = it->second;
        map.erase(it);

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {

        return nums[random() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, int> map;    // map[n]：整数n的索引
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */