#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> map;    // map[n]：整数n上次出现的位置
        for (int i = 0; i < nums.size(); i++) {
            auto it = map.find(target - nums[i]);
            if (it != map.end()) {
                return { it->second, i };
            }
            map[nums[i]] = i;
        }
        return {};
    }
};