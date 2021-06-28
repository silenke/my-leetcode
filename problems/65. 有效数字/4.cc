#include "..\..\leetcode.h"

class Solution {
public:
    bool isNumber(string s) {

        bool Num = false;
        bool Dot = false;
        bool Sig = false;
        bool Exp = false;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                Num = true;
            }
            else if (c == '.') {
                if (Dot || Exp) return false;
                Dot = true;
            }
            else if (c == '+' || c == '-') {
                if (Sig || Dot || Num) return false;
                Sig = true;
            }
            else if (c == 'E' || c == 'e') {
                if (Exp || !Num) return false;
                Exp = true;
                Num = Dot = Sig = false;
            }
            else {
                return false;
            }
        }
        return Num;
    }
};