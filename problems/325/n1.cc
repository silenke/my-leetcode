#include "..\..\leetcode.h"

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {

        unordered_map<int, int> map;    // map[sum]：前缀和sum最早出现的位置
        map[0] = -1;
        int res = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            auto it = map.find(sum - k);
            if (it != map.end()) res = max(res, i - it->second);
            if (map.find(sum) == map.end()) map[sum] = i;
        }
        return res;
    }
};