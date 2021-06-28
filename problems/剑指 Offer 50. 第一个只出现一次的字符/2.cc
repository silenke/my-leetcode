#include "..\..\leetcode.h"

class Solution {
public:
    char firstUniqChar(string s) {

        vector<int> map(128, 0);
        vector<int> set;
        for (char c : s) {
            if (map[c]++ == 0) set.push_back(c);
        }
        for (char c : set) {
            if (map[c] == 1) return c;
        }
        return ' ';
    }
};