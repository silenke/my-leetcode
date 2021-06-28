#include "..\..\leetcode.h"

class Solution {
public:
    bool isUnique(string astr) {

        int n = (128 + 7) / 8;
        vector<char> bits(n);
        for (char c : astr) {
            int i = c / 8;
            int j = c % 8;
            if (bits[i] & (1 << j)) return false;
            bits[i] |= (1 << j);
        }
        return true;
    }
};