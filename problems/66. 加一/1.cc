#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for (int i = digits.size() - 1; i >= 0; i--) {
            if (++digits[i] %= 10) return digits;
        }
        digits[0] = 1;
        digits.emplace_back(0);
        return digits;
    }
}; 