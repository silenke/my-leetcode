#include "..\..\leetcode.h"

class Solution {
public:
    int compareVersion(string version1, string version2) {

        const int n1 = version1.size();
        const int n2 = version2.size();
        int i = 0, j = 0;
        while (i < n1 || j < n2) {
            int a = 0, b = 0;
            while (i < n1 && version1[i] != '.') {
                a = a * 10 + (version1[i++] - '0');
            }
            while (j < n2 && version2[j] != '.') {
                b = b * 10 + (version2[j++] - '0');
            }
            if (a < b) return -1;
            if (a > b) return 1;
            i++, j++;
        }
        return 0;
    }
};