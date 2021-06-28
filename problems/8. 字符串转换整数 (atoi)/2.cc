#include "..\..\leetcode.h"

class Solution {
public:
    int strToInt(string str) {

        const int n = str.size();
        int i = 0;
        while (i < n && str[i] == ' ') i++;
        if (i == n) return 0;
        int sign = 1;
        if (str[i] == '+') {
            i++;
        }
        else if (str[i] == '-') {
            i++;
            sign = -1;
        }
        int res = 0;
        while (i < n) {
            if (!isdigit(str[i])) break;
            if (res > INT_MAX / 10 || res == INT_MAX / 10 && str[i] > '7') {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + (str[i++] - '0');
        }
        return res * sign;
    }
};