#include "..\..\leetcode.h"

class Solution {
public:
    int compareVersion(string version1, string version2) {

        char c;
        int n1, n2;
        istringstream i1(version1);
        istringstream i2(version2);
        while (bool(i1 >> n1) + bool(i2 >> n2)) {
            if (n1 > n2) return 1;
            if (n1 < n2) return -1;
            n1 = n2 = 0;
            i1 >> c;
            i2 >> c;
        }
        return 0;
    }
};