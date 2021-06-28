#include "..\..\leetcode.h"

class Solution {
public:
    int nthUglyNumber(int n) {

        static vector<int> nums;
        if (nums.empty()) {
            for (long long i = 1; i <= INT_MAX; i *= 2) {
                for (long long j = i; j <= INT_MAX; j *= 3) {
                    for (long long k = j; k <= INT_MAX; k *= 5) {
                        nums.emplace_back(k);
                    }
                }
            }
        }
        sort(nums.begin(), nums.end());
        return nums[n - 1];
    }
};