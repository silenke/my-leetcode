#include "..\..\leetcode.h"

class Solution {
public:
    int calculate(string s) {

        int i = 0;
        return calculate(s, i);
    }

private:
    int calculate(const string& s, int& i) {

        int res = 0;
        char sign = '+';
        int num = 0;
        while (i < s.size() && s[i] != ')') {
            char c = s[i++];
            if (c == '(') {
                num = calculate(s, i);
            }
            else if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if (c == '+' || c == '-' || i == s.size() || s[i] == ')') {
                if (sign == '+') res += num;
                else if (sign == '-') res -= num;
                sign = c;
                num = 0;
            }
        }
        i++;
        return res;
    }
};