#include "..\..\leetcode.h"

class Solution {
public:
    bool isNumber(string s) {

        const int n = s.size();
        int l = 0;
        while (l < n && s[l] == ' ') l++;
        int r = n - 1;
        while (r >= l && s[r] == ' ') r--;
        bool Sig = false;   // 出现过+/-
        bool Num = false;   // 出现过数字
        bool Dot = false;   // 出现过.
        bool Exp = false;  // 出现过E/e
        for (int i = l; i <= r; i++) {
            char c = s[i];
            if (c == '+' || c == '-') {
                if (Sig || Num || Dot) return false;
                Sig = true;
            }
            else if ('0' <= c && c <= '9') {
                Num = true;
            }
            else if (c == '.') {
                if (Dot || Exp) return false;
                Dot = true;
            }
            else if (c == 'E' || c == 'e') {
                if (Exp || !Num) return false;
                Exp = true;
                Sig = Num = Dot = false;
            }
            else {
                return false;
            }
        }
        return Num;
    }
};