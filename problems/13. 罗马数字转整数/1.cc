#include "..\..\leetcode.h"

class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> map{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int res = 0;
        int p = 0;
        for (char c : s) {
            res += map[c];
            if (map[p] < map[c]) res -= map[p] * 2;
            p = c;
        }
        return res;
    }
};