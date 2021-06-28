#include "..\..\leetcode.h"

class Solution {
public:
    bool isNumber(string s) {

        vector<unordered_map<int, int>> map{
            {{0, 0}, {2, 2}, {1, 1}, {3, 4}},
            {{2, 2}, {3, 4}},
            {{2, 2}, {3, 3}, {4, 6}, {0, 9}},
            {{2, 5}, {4, 6}, {0, 9}},
            {{2, 5}},
            {{2, 5}, {4, 6}, {0, 9}},
            {{1, 7}, {2, 8}},
            {{2, 8}},
            {{2, 8}, {0, 9}},
            {{0, 9}}
        };

    s.push_back(' ');
    int status = 0;
    for (char c : s) {
        auto it = map[status].find(symbol(c));
        if (it == map[status].end()) return false;
        status = it->second;
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
        return -1;
    }
};