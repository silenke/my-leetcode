#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int res = INT_MAX;
        int sum = 0;    // 窗口和
        int l = 0;  // 左边界
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum - nums[l] >= s) {
                sum -= nums[l++];   // 收缩左边界
            }
            if (sum >= s) {
                res = min(res, i - l + 1);
            }
        }
        return res < INT_MAX ? res : 0;
    }
};