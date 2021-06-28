#include "..\..\leetcode.h"

class Solution {
public:
    bool canCross(vector<int>& stones) {

        for (int i = 1; i < stones.size(); i++) {
            if (stones[i] - stones[i - 1] > i) return false;
        }
        function<bool(int, int)> dfs = [&](int target, int k) {
            if (target == stones.back()) return true;
            if (!binary_search(stones.begin(), stones.end(), target)) return false;
            for (int l = k + 1; l >= k - 1; l--) {
                if (l <= 0) break;
                if (dfs(target + l, l)) return true;
            }
            return false;
        };
        return dfs(1, 1);
    }
};