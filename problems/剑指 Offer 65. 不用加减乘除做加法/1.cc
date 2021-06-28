#include "..\..\leetcode.h"

class Solution {
public:
    int add(int a, int b) {

        while (b) {
            int c = a ^ b;
            b = static_cast<unsigned int>(a & b) << 1;
            a = c;
        }
        return a;
    }
};