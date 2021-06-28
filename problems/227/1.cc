#include "..\..\leetcode.h"

#include "..\..\leetcode.h"

class Solution {
public:
    int calculate(string s) {

        int num = 0;
        int sign = '+';
        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                switch(sign) {
                    case '+':
                        stk.emplace(num);
                        break;
                    case '-':
                        stk.emplace(-num);
                        break;
                    case '*':
                        num = stk.top() * num; stk.pop();
                        stk.emplace(num);
                        break;
                    case '/':
                        num = stk.top() / num; stk.pop();
                        stk.emplace(num);
                        break;
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