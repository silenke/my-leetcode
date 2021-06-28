#include "..\..\leetcode.h"

class Solution {
public:
    int calculate(string s) {

        stack<int> stk;
        char sign = '+';
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == s.size() - 1) {
                if (sign == '+') {
                    stk.emplace(num);
                }
                else if (sign == '-') {
                    stk.emplace(-num);
                }
                else if (sign == '*') {
                    num = stk.top() * num; stk.pop();
                    stk.emplace(num);
                }
                else {
                    num = stk.top() / num; stk.pop();
                    stk.emplace(num);
                }
                sign = c;
                num = 0;
            }
        }
        
        int res = 0;
        while (!stk.empty()) {
            res += stk.top(); stk.pop();
        }
        return res;
    }
};