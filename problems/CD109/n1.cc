#include "..\..\leetcode.h"

class Solution {
public:
    int last(int n, int m) {
        
        int k = 0;
        for (int i = 2; i <= n; i++) {
            k = (k + m) % i;
        }
        return k + 1;
    }
};