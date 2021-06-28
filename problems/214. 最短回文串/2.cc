#include "..\..\leetcode.h"

class Solution {
public:
    string shortestPalindrome(string s) {

        string str(s);
        str.push_back('#');
        for (int i = s.size() - 1; i >= 0; i--) {
            str.push_back(s[i]);
        }

        const int n = str.size();
        vector<int> next(n + 1);
        next[0] = next[1] = 0;
        int i = 2, j = 0;
        while (i <= n) {
            if (str[j] == str[i - 1]) next[i++] = ++j;
            else if (j > 0) j = next[j];
            else next[i++] = 0;
        }

        string res;
        int k = next[n];
        for (int i = s.size() - 1; i >= k; i--) {
            res.push_back(s[i]);
        }
        res += s;
        return res;
    }
};