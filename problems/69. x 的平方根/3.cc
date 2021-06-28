#include "..\..\leetcode.h"

class Solution {
public:
    int mySqrt(int x) {

        int y = x;
        while (y > x / y) {
            y = (y + x / y) / 2;
        }
        return y;
    }
};