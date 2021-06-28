#include "..\..\leetcode.h"

class Solution {
public:
    int calculate(string s) {

        int i = 0;
        return calculate(s, i);
    }

private:
    int calculate(const string& s, int& i) {

        stack<int> stk;
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
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == s.size() || s[i] == ')') {
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
                else if (sign == '/') {
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
        i++;
        return res;
    }
};