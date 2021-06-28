#include "..\..\leetcode.h"

class Solution {
public:
    int countSubstrings(string s) {

        string str;
        const int n = s.size() * 2 + 1;
        str.push_back('~');
        for (int i = 0, j = 0; i < n; i++) {
            str.push_back(i & 1 ? s[j++] : '#');
        }
        str.push_back('!');

        vector<int> rads(n);
        int last = 0;
        rads[last] = 1;
        int res = 0;
        for (int i = 1; i < n; i++) {
            int r = last + rads[last];
            rads[i] = i >= r ? 1 : min(r - i, rads[last * 2 - i]);
            while (str[i - rads[i]] == str[i + rads[i]]) {
                rads[i]++;
            }
            if (i + rads[i] > r) {
                last = i;
            }
            res += rads[i] / 2;
        }
        return res;
    }
};