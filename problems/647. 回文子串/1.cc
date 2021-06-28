#include "..\..\leetcode.h"

class Solution {
public:
    int countSubstrings(string s) {

        int res = 0;
        auto count = [&](int l, int r) {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res++;
                l--; r++;
            }
        };
        for (int i = 0; i < s.size(); i++) {
            count(i, i);
            count(i, i + 1);
        }
        return res;
    }
};