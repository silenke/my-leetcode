#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (const auto& i : intervals) {
            if (res.empty() || i[0] > res.back()[1]) {
                res.emplace_back(move(i));
            }
            else {
                res.back()[1] = max(res.back()[1], i[1]);
            }
        }
        return res;
    }
};