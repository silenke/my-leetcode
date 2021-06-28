#include "..\..\leetcode.h"

class Solution {
public:
    string shortestPalindrome(string s) {

        const int n = s.size();
        if (n < 2) return s;

        vector<int> next(n + 1);
        next[0] = next[1] = 0;
        int i = 2, j = 0;
        while (i < n) {
            if (s[j] == s[i - 1]) next[i++] = ++j;
            else if (j > 0) j = next[j];
            else next[i++] = 0;
        }

        i = n - 1, j = 0;
        while (i >= 0 && j < n) {
            if (s[i] == s[j]) i--, j++;
            else if (j > 0) j = next[j];
            else i--;
        }

        string res;
        for (i = n - 1; i >= j; i--) {
            res.push_back(s[i]);
        }
        res += s;
        return res;
    }
};