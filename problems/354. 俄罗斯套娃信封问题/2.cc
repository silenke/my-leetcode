#include "..\..\leetcode.h"

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] != b[0]) return a[0] < b[0];
                return a[1] > b[1];                
            }
        );
        int res = 0;
        vector<int> nums;
        for (const auto& e : envelopes) {
            auto it = lower_bound(nums.begin(), nums.end(), e[1]);
            if (it != nums.end()) *it = e[1];
            else nums.emplace_back(e[1]);
        }
        return nums.size();
    }
};