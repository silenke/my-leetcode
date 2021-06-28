#include "..\..\leetcode.h"

class Solution {
public:
    bool isNumber(string s) {

        bool Num = false;
        bool Dot = false;
        bool Exp = false;
        int i = 0;
        while (i < s.size() && s[i] == ' ') i++;
        for (int j = i; j < s.size(); j++) {
            char c = s[j];
            if (c >= '0' && c <= '9') {
                Num = true;
            }
            else if (c == '.') {
                if (Dot || Exp) return false;
                Dot = true;
            }
            else if (c == 'E' || c == 'e') {
                if (Exp || !Num) return false;
                Exp = true;
                Num = false;
            }
            else if (c == '+' || c == '-') {
                if (j != i && s[j - 1] != 'E' && s[j - 1] != 'e') return false;
            }
            else {
                return false;
            }
        }
        return Num;
    }
};