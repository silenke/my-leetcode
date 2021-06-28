#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        if (intervals.empty()) return {newInterval};

        int l = -1, r = intervals.size();
        int s = newInterval[0], e = newInterval[1];
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] < s) {
                l = i;
            }
            else if (intervals[i][0] > e) {
                r = i;
                break;
            }
            else {
                s = min(s, intervals[i][0]);
                e = max(e, intervals[i][1]);
            }
        }
        vector<vector<int>> res;
        res.insert(res.end(), intervals.begin(), intervals.begin() + l + 1);
        res.push_back({s, e});
        res.insert(res.end(), intervals.begin() + r, intervals.end());
        return res;
    }
};