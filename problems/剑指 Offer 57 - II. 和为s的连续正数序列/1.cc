#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {

        vector<vector<int>> res;
        int sum = 0;
        int l = 1;
        for (int r = 1; r <= target / 2 + 1; r++) {
            sum += r;
            while (sum > target) {
                sum -= l++;
            }
            if (sum == target) {
                vector<int> tmp(r - l + 1);
                iota(tmp.begin(), tmp.end(), l);
                res.emplace_back(move(tmp));
            }
        }
        return res;
    }
};