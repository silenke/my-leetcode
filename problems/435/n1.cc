#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int>& b){
                return a[0] < b[0];
            });

        int res = intervals.size();
        int left = INT_MAX;
        for (int i = intervals.size() - 1; i >= 0 ; i--) {
            if (intervals[i][1] <= left) {
                res--;
                left = intervals[i][0];
            }
        }
        return res;
    }
};