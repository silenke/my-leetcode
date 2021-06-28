#include "..\..\leetcode.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        vector<int> counts(32); // counts[i]：i位置1出现的次数
        for (int n : nums) {
            for (int i = 0; i < 31; i++) {
                counts[i] += (n >> i) & 1;
            }
        }
        int res = 0;
        for (int i = 0; i < 31; i++) {
            res |= counts[i] % 3 << i;
        }
        return res;
    }
};