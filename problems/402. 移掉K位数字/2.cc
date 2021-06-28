#include "..\..\leetcode.h"

class Solution {
public:
    string removeKdigits(string num, int k) {

        if (num.size() == k) return "0";

        string s;
        int n = num.size() - k;
        for (char c : num) {
            while (!s.empty() && s.back() > c && k-- > 0) {
                s.pop_back();
            }
            s.push_back(c);
        }
        s.resize(n);
        int i = 0;
        while (i < s.size() - 1 && s[i] == '0') i++;
        return i == 0 ? s : s.substr(i);
    }
};