#include "..\..\leetcode.h"

class Solution {
public:
    int couples(int n) {
        
        if (n <= 1) return 0;
        return n * 2 - 3;
    }
};