#include "..\..\leetcode.h"

class Solution {
public:
    int longestValidParentheses(string s) {

        const int n = s.size();
        int res = 0;
        int l = 0, r = 0;
        for (char c : s) {
            if (c == '(') l++;
            else if (++r == l) res = max(res, l * 2);
            else if (r > l) l = r = 0;
        }
        l = r = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') r++;
            else if (++l == r) res = max(res, l * 2);
            else if (l > r) l = r = 0;
        }
        return res;
    }
};