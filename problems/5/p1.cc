#include "..\..\leetcode.h"

class Solution {
public:
    string longestPalindrome(string s) {

        int l = -1, len = 0;
        for (int i = 0; i < s.size(); i++) {
            auto [l1, len1] = extend(s, i -1, i + 1);
            auto [l2, len2] = extend(s, i, i + 1);
            if (len1 > len) { l = l1; len = len1; };
            if (len2 > len) { l = l2; len = len2; };
        }
        return s.substr(l, len);
    }

private:
    pair<int, int> extend(const string& s, int l, int r) {

        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--; r++;
        }
        return { l + 1, r - l - 1 };
    }
};