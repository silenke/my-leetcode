#include "..\..\leetcode.h"

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> map{{0, 1}};
        int sum = 0;
        int res = 0;
        for (int n : nums) {
            sum += n;
            res += map[sum - k];
            map[sum]++;
        }
        return res;
    }
};