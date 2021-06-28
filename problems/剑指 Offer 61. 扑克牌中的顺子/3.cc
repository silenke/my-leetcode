#include "..\..\leetcode.h"

class Solution {
public:
    bool isStraight(vector<int>& nums) {

        bitset<14> set;
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for (int n : nums) {
            if (n == 0) continue;
            if (set[n]) return false;
            set[n] = true;
            minNum = min(minNum, n);
            maxNum = max(maxNum, n);
        }
        return maxNum - minNum < 5;
    }
};