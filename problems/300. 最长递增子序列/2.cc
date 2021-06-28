#include "..\..\leetcode.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> res;
        for (int n : nums) {
            auto it = lower_bound(res.begin(), res.end(), n);
            if (it != res.end()) *it = n;
            else res.emplace_back(n);
        }
        return res.size();
    }
};