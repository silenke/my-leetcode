#include "..\..\leetcode.h"

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> map;
        for (int n : arr) map[n]++;
        unordered_set<int> set;
        for (const auto& p : map) {
            if (set.find(p.second) != set.end()) return false;
            set.insert(p.second);
        }
        return true;
    }
};