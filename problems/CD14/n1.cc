#include "..\..\leetcode.h"

class Solution {
public:
    int maxLength(vector<int>& nums, int k) {

        const int n = nums.size();

        vector<int> mins(n);    // nums[i]：以位置i开始的最小和
        vector<int> rights(n);    // rights[i]：以位置i开始的最小和的右边界
        mins[n - 1] = nums[n - 1];
        rights[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            mins[i] = nums[i];
            rights[i] = i;
            if (mins[i + 1] <= 0) {
                mins[i] += mins[i + 1];
                rights[i] = rights[i + 1];
            }
        }

        int res = 0;
        int r = 0;
        int sum = 0;
        for (int l = 0; r < n; l++) {
            while (r < n && sum + mins[r] <= k) {
                sum += mins[r];
                r = rights[r] + 1;
            }
            res = max(res, r - l);
            if (l < r) sum -= nums[l];
            else r++;
        }
        return res;
    }
};