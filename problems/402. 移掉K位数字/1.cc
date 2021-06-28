#include "..\..\leetcode.h"

class Solution {
public:
    string removeKdigits(string num, int k) {

        string s;
        for (char c : num) {
            while (k && !s.empty() && s.back() > c) {
                k--;
                s.pop_back();
            }
            s.push_back(c);
        }
        while (k && !s.empty()) {
            k--;
            s.pop_back();
        }
        if (s.empty()) return "0";
        int i = 0;
        while (i < s.size() - 1 && s[i] == '0') i++;
        return i == 0 ? s : s.substr(i);
    }
};