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

                next.emplace_back();
                double a = nums[i], b = nums[j];

                next.back() = a + b;
                if (dfs(next)) return true;

                next.back() = a - b;
                if (dfs(next)) return true;

                next.back() = a * b;
                if (dfs(next)) return true;
                
                next.back() = a / b;
                if (dfs(next)) return true;

                next.back() = b - a;
                if (dfs(next)) return true;
                
                next.back() = b / a;
                if (dfs(next)) return true;
            }
        }
        return false;
    }
};