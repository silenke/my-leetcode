#include "..\..\leetcode.h"

class Solution {
public:
    int longestValidParentheses(string s) {

        const int n = s.size();
        int res = 0;
        int last = -1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') ++count;
            else if (--count == 0) res = max(res, i - last);
            else if (count < 0) last = i, count = 0;
        }
        last = n;
        count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') ++count;
            else if (--count == 0) res = max(res, last - i);
            else if (count < 0) last = i, count = 0;
        }
        return res;
    }
};