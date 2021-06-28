#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> map;    // map[n]：整数n出现的次数
        for (int n : nums1) {
            map[n]++;
        }

        vector<int> res;
        for (int n : nums2) {
            auto it = map.find(n);
            if (it != map.end()) {
                res.emplace_back(n);
                if (--it->second == 0) {
                    map.erase(it);
                }
            }
        }
        return res;
    }
};