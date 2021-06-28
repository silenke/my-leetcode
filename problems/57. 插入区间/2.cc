#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        if (intervals.empty()) return {newInterval};

        int l = -1, r = intervals.size();
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] < newInterval[0]) {
                l = i;
            }
            else if (intervals[i][0] > newInterval[1]) {
                r = i;
                break;
            }
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        vector<vector<int>> res(intervals.begin(), intervals.begin() + l + 1);
        res.emplace_back(newInterval);
        res.insert(res.end(), intervals.begin() + r, intervals.end());
        return res;
    }
};