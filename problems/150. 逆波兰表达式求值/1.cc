#include "..\..\leetcode.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> s;
        for (const string& str : tokens) {
            if (isdigit(str.back())) {
                s.emplace(stoi(str));
            }
            else {
                int n1 = s.top(); s.pop();
                int n2 = s.top(); s.pop();
                int n;
                switch (str.back()) {
                    case '+' : n = n2 + n1; break;
                    case '-' : n = n2 - n1; break;
                    case '*' : n = n2 * n1; break;
                    case '/' : n = n2 / n1; break;
                }
                s.emplace(n);
            }
        }
        return s.top();
    }
};