#include "..\..\leetcode.h"

class Solution {
public:
    char firstUniqChar(string s) {

        vector<int> map(128);
        for (char c : s) map[c]++;
        for (char c : s) {
            if (map[c] == 1) return c;
        }
        return ' ';
    }
};