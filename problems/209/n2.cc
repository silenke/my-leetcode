#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int n = nums.size();

        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {  // 存放[0,i)的和
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(sums.begin() + i + 1, sums.end(), sums[i] + s);
            if (it != sums.end()) {
                res = min(res, static_cast<int>(it - sums.begin()) - i);
            }
            else {
                break;
            }
        }
        return res < INT_MAX ? res : 0;
    }
};