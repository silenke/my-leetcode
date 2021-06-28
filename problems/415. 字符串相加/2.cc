#include "..\..\leetcode.h"

class Solution {
public:
    string addStrings(string num1, string num2) {

        string res;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int c = 0;
        while (i >= 0 || j >= 0 || c > 0) {
            if (i >= 0) c += num1[i--] - '0';
            if (j >= 0) c += num2[j--] - '0';
            res.push_back(c % 10 + '0');
            c /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};