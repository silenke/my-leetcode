#include "..\..\leetcode.h"

class Solution {
public:
    int findNthDigit(int n) {

        long start = 1;
        int digit = 1;
        while (n > start * digit * 9) {
            n -= start * digit * 9;
            start *= 10;
            digit++;
        }
        start += (n - 1) / digit;
        digit -= (n - 1) % digit + 1;
        while (digit--) {
            start /= 10;
        }
        return start % 10;
    }
};