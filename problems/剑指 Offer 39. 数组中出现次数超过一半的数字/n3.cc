#include "..\..\leetcode.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int res = 0;
        int count = 0;
        for (int n : nums) {
            if (count == 0) res = n;
            count += res == n ? 1 : -1;
        }
        return res;
    }
};