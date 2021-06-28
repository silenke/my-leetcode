#include "..\..\leetcode.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int res = 1e5;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target) return sum;
                if (abs(sum - target) < abs(res - target)) res = sum;
                if (sum < target) {
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                }
                else {
                    r--;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }
        return res;
    }
};