#include "..\..\leetcode.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int res = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int n : nums) {
                count += (n >> i) & 1;
            }
            res |= (count % 3) << i;
        }
        return res;
    }
};