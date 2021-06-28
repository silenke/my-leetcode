#include "..\..\leetcode.h"

class Solution {
public:
    bool isNumber(string s) {

        vector<vector<int>> map {
            {0, 1, 2, 4, -1, -1},
            {-1, -1, 2, 4, -1, -1},
            {9, -1, 2, 3, 6, -1},
            {9, -1, 5, -1, 6, -1},
            {-1, -1, 5, -1, -1, -1},
            {9, -1, 5, -1, 6, -1},
            {-1, 7, 8, -1, -1, -1},
            {-1, -1, 8, -1, -1, -1},
            {9, -1, 8, -1, -1, -1},
            {9, -1, -1, -1, -1, -1},
        };

    s.push_back(' ');
    int status = 0;
    for (char c : s) {
        status = map[status][symbol(c)];
        if (status == -1) return false;
    }
    return status == 9;
}

private:
    int symbol(char c) {
        if (c == ' ') return 0;
        if (c == '+' || c == '-') return 1;
        if (c >= '0' && c <= '9') return 2;
        if (c == '.') return 3;
        if (c == 'e' || c == 'E') return 4;
        return 5;
    }
};