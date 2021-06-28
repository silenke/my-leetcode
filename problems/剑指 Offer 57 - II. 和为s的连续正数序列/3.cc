#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {

        vector<vector<int>> res;
        for (long l = 1; ; l++) {
            double r = (-1 + sqrt(4 * (l * l - l + 2 * target) + 1)) / 2;
            if (l >= r) break;
            if (r != static_cast<int>(r)) continue;
            vector<int> tmp(r - l + 1);
            iota(tmp.begin(), tmp.end(), l);
            res.emplace_back(move(tmp));
        }
        return res;
    }
};