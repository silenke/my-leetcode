#include "..\..\leetcode.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int, int> map;
        int res = 0;
        for (int n : nums) {
            if (map.find(n) != map.end()) continue;

            auto lit = map.find(n - 1);
            auto rit = map.find(n + 1);

            int l = lit != map.end() ? lit->second : 0;
            int r = rit != map.end() ? rit->second : 0;
            int len = l + r + 1;

            map[n] = map[n - l] = map[n + r] = len;

            res = max(res, len);
        }
        return res;
    }
};