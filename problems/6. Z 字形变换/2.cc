#include "..\..\leetcode.h"

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows < 2) return s;

        const int n = s.size();
        string res;
        int d = (numRows - 1) * 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < n; j += d) {
                res += s[j];
                if (0 < i && i < numRows -1) {
                    int k = j + d - i * 2;
                    if (k < n) res += s[k];
                }
            }
        }
        return res;
    }
};