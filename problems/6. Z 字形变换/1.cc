#include "..\..\leetcode.h"

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows < 2) return s;

        vector<string> rows(min(static_cast<int>(s.size()), numRows));
        int i = 0, flag = -1;
        for (char c : s) {
            rows[i].push_back(c);
            if (i == 0 || i == numRows - 1) {
                flag  = -flag;
            }
            i += flag;
        }
        string res;
        for (string& str : rows) {
            res += str;
        }
        return res;
    }
};