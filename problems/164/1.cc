#include "..\..\leetcode.h"

class Solution {
public:
    int maximumGap(vector<int>& nums) {

        if (nums.size() < 2) return 0;

        int min_num = INT_MAX;
        int max_num = INT_MIN;
        for (int x : nums) {
            min_num = min(min_num, x);
            max_num = max(max_num, x);
        }
        
        if (min_num == max_num) return 0;

        int n = nums.size();
        vector<int> mins(n + 1, INT_MAX);
        vector<int> maxs(n + 1, INT_MIN);
        for (int x : nums) {
            int i = static_cast<long long>(x - min_num) * n / (max_num - min_num);
            mins[i] = min(mins[i], x);
            maxs[i] = max(maxs[i], x);
        }

        int res = INT_MIN;
        int last = INT_MAX;
        for (int i = 0; i <= n; i++) {
            if (mins[i] != INT_MAX) {
                res = max(res, mins[i] - last);
                last = maxs[i];
            }
        }
        return res;
    }
};