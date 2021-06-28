#include "..\..\leetcode.h"

class Solution {
public:
    bool canPermutePalindrome(string s) {

        vector<int> counts(128, 0);
        for (char c : s) {
            counts[c] ^= 1;
        }
        int res = 0;
        for (int c : counts) {
            res += c;
        }
        return res < 2;
    }
};