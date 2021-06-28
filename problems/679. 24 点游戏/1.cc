#include "..\..\leetcode.h"

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {

        vector<double> next;
        for (int n : nums) next.emplace_back(n);
        return dfs(next);
    }

private:
    const double eps = 1e-6;

    bool dfs(const vector<double>& nums) {
        
        const int n = nums.size();
        if (n == 1) {
            return abs(nums[0] - 24) < eps;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                vector<double> next;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) {
                        next.emplace_back(nums[k]);
                    }
                }

                vector<double> back{nums[i] + nums[j], nums[i] - nums[j],
                    nums[i] * nums[j], nums[i] / nums[j],
                    nums[j] - nums[i], nums[j] / nums[i]};


                for (double b : back) {
                    next.emplace_back(b);
                    if (dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
};