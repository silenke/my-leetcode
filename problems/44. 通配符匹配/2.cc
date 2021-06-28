#include "..\..\leetcode.h"

class Solution {
public:
    bool isMatch(string s, string p) {

        const int m = s.size();
        const int n = p.size();
        int i = 0, j = 0;
        int match = 0, start = -1;
        while (i < m) {
            if (j < n && (p[j] == s[i] || p[j] == '?')) {
                i++, j++;
            }
            else if (j < n && p[j] == '*') {
                match = i;
                start = j++;
            }
            else if (start != -1) {
                j = start + 1;
                i = ++match;
            }
            else {
                return false;
            }
        }
        while (j < n) {
            if (p[j++] != '*') return false;
        }
        return true;
    }
};