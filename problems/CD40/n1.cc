#include "..\..\leetcode.h"

class Solution {
public:
    int maximumGap(vector<int>& nums) {

        int n = nums.size();
        if (n < 2) return 0;

        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for (int x : nums) {
            minNum = min(minNum, x);
            maxNum = max(maxNum, x);
        }
        
        if (minNum == maxNum) return 0;

        vector<int> mins(n + 1, INT_MAX);
        vector<int> maxs(n + 1, INT_MIN);
        for (int x : nums) {
            int i = (long long)(x - minNum) * n / (maxNum - minNum);
            mins[i] = min(mins[i], x);
            maxs[i] = max(maxs[i], x);
        }

        int res = INT_MIN;
        int lastMax = INT_MAX;
        for (int i = 0; i < n + 1; i++) {
            if (mins[i] != INT_MAX) {
                res = max(res, mins[i] - lastMax);
                lastMax = maxs[i];
            }
        }
        return res;
    }
};