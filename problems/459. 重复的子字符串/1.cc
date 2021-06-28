#include "..\..\leetcode.h"

class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        const int n = s.size();
        vector<int> next(n + 1);
        generate(s, next);
        return next[n] != 0 && n % (n - next[n]) == 0;
    }

private:
    void generate(const string& s, vector<int>& next) {

        next[0] = -1;
        next[1] = 0;
        int i = 2, j = 0;
        while (i <= s.size()) {
            if (s[j] == s[i - 1]) next[i++] = ++j;
            else if (j > 0) j = next[j];
            else next[i++] = 0;
        }
    }
};