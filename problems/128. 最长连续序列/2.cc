#include "..\..\leetcode.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> set(nums.begin(), nums.end());
        int res = 0;
        for (int n : set) {
            if (set.find(n - 1) == set.end()) {
                int l = 1;
                while (set.find(++n) != set.end()) l++;
                res = max(res, l);
            }
        }
        return res;
    }
};