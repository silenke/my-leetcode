#include "..\..\leetcode.h"

class Solution {
public:
    string shortestPalindrome(string s) {

        const int n =  s.size() * 2 + 1;
        string str;
        for (int i = 0, j = 0; i < n; i++) {
            str.push_back(i & 1 ? s[j++] : '#');
        }

        vector<int> r(n);
        int last = n - 1;
        r[last] = 1;
        for (int i = last - 1; i >= 0; i--) {
            int l = last - r[last];
            r[i] = i <= l ? 1 : min(i - l, r[last * 2 - i]);
            while (i - r[i] >= 0 && i + r[i] < n && str[i - r[i]] == str[i + r[i]]) {
                r[i]++;
            }
            if (i - r[i] < l) {
                last = i;
                if (i - r[i] < 0) break;
            }
        }

        string res;
        int k = (last + r[last] - 1) / 2;
        for (int i = s.size() - 1; i >= k; i--) {
            res.push_back(s[i]);
        }
        res += s;
        return res;
    }
};