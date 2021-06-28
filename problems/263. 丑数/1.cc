#include "..\..\leetcode.h"

class Solution {
public:
    bool isUgly(int num) {

        if (num == 0) return false;

        vector<int> factors{2, 3, 5};
        for (int f : factors) {
            while (num % f == 0) num /= f;
        }
        return num == 1;
    }
};