#include "..\..\leetcode.h"

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int>& b){
                return a[1] < b[1];
            });

        int res = intervals.size();
        int r = INT_MIN;    // 当前最右边界
        for (auto& i : intervals) {
            if (i[0] >= r) {
                res--;
                r = i[1];
            }
        }
        return res;
    }
};