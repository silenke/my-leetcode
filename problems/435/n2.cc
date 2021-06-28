#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int>& b){ return a[1] < b[1]; });

        int res = intervals.size();
        int right = INT_MIN;
        for (auto& i : intervals) {
            if (i[0] >= right) {
                res--;
                right = i[1];
            }
        }
        return res;
    }
};