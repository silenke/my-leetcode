#include "..\..\leetcode.h"

class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) return false;

        int y = x;
        int z = 0;
        while (y) {
            if (z > INT_MAX / 10) return false;
            z = z * 10 + y % 10;
            y /= 10;
        }
        return x == z;
    }
};