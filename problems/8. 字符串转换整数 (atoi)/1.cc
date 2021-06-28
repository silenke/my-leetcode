#include "..\..\leetcode.h"

class Solution {
public:
    int myAtoi(string s) {

        bool begin = false;
        int sign = 1;
        int res = 0;
        for (char c : s) {
            if (begin) {
                if (!isdigit(c)) break;
                if (res > INT_MAX / 10 || res == INT_MAX / 10 && c > '7') {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                res = res * 10 + (c - '0');
            }
            else {
                if (isdigit(c)) {
                    begin = true;
                    res = c - '0';
                }
                else if (c == '+') {
                    begin = true;
                }
                else if (c == '-') {
                    begin = true;
                    sign = -1;
                }
                else if (c != ' ') {
                    return 0;
                }
            }
        }
        return res * sign;
    }
};