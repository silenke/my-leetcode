#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {

        vector<vector<int>> res;
        int l = 1, r = 2;
        while (l < r) {
            int sum = (l + r) * (r - l + 1) / 2;
            if (sum == target) {
                vector<int> tmp(r - l + 1);
                iota(tmp.begin(), tmp.end(), l);
                res.emplace_back(move(tmp));
                l++, r++;
            }
            else if (sum < target) {
                r++;
            }
            else {
                l++;
            }
        }
        return res;
    }
};