#include "..\..\leetcode.h"

class Solution {
public:
    int calculate(string s) {

        int res = 0;
        int sign = 1;
        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }
                res += sign * num;
                i--;
            }
            else if (c == '+') {
                sign = 1;
            }
            else if (c == '-') {
                sign = -1;
            }
            else if (c == '(') {
                stk.emplace(res);
                stk.emplace(sign);
                res = 0;
                sign = 1;
            }
            else if (c == ')') {
                res *= stk.top(); stk.pop();
                res += stk.top(); stk.pop();
            }
        }
        return res;
    }
};