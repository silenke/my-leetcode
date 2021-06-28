#include "..\..\leetcode.h"

class Solution {
public:
    bool canCross(vector<int>& stones) {

        unordered_set<int> set;
        for (int i = 1; i < stones.size(); i++) {
            if (stones[i] - stones[i - 1] > i) return false;
            set.insert(stones[i]);
        }
        function<bool(int, int)> dfs = [&](int target, int k) {
            if (target == stones.back()) return true;
            if (set.find(target) == set.end()) return false;
            for (int l = k + 1; l >= k - 1; l--) {
                if (l <= 0) break;
                if (dfs(target + l, l)) return true;
            }
            return false;
        };
        return dfs(1, 1);
    }
};