#include "..\..\leetcode.h"

class Solution {
public:
    bool isUnique(string astr) {

        int map = 0;
        for (char c : astr) {
            int i = 1 << (c - 'a');
            if (map & i) return false;
            map |= i;
        }
        return true;
    }
};