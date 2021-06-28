#include "..\..\leetcode.h"

class Solution {
public:
    string longestPalindrome(string s) {

        const int n = s.size() * 2 + 1;
        string str(n, '#');
        for (int i = 1, j = 0; i < n; i += 2, j++) {
            str[i] = s[j];
        }

        vector<int> radius(n);
        radius[0] = 1;
        int last = 0;
        int res = 0;
        for (int i = 1; i < n; i++) {
            int r = last + radius[last];
            radius[i] = i >= r ? 1 : min(r - i, radius[last * 2 - i]);
            while (i - radius[i] >= 0 && i + radius[i] < n && str[i - radius[i]] == str[i + radius[i]]) {
                radius[i]++;
            }
            if (i + radius[i] > r) {
                last = i;
                if (radius[i] > radius[res]) {
                    res = i;
                }
            }
        }
        return s.substr((res - radius[res] + 1) / 2, radius[res] - 1);
    }
};