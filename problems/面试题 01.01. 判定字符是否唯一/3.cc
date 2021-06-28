#include "..\..\leetcode.h"

class Solution {
public:
    bool isUnique(string astr) {
        
        bitset<128> set;
        for (char c : astr) {
            if (set.test(c)) return false;
            set.set(c, 1);
        }
        return true;
    }
};