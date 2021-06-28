#include "..\..\leetcode.h"

class Solution {
public:
    string replaceSpace(string s) {

        string res;
        for (char c : s) {
            if (c != ' ') res.push_back(c);
            else res.append("%20");
        }
        return res;
    }
};