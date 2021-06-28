#include "..\..\leetcode.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int res = INT_MIN;
        int count = 1;
        for (int n : nums) {
            if (n == res) count++;
            else if (count == 1) res = n;
            else count--;
        }
        return res;
    }
};