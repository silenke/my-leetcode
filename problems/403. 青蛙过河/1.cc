#include "..\..\leetcode.h"

class Solution {
public:
    bool canCross(vector<int>& stones) {

        unordered_map<int, unordered_set<int>> map;
        //  map[i]：跳到位置i的所有步长
        for (int s : stones) {
            map[s] = unordered_set<int>();
        }
        map[0].insert(0);
        for (int s : stones) {
            for (int k : map[s]) {
                for (int l = k - 1; l <= k + 1; l++) {
                    if (l <= 0) continue;
                    if (s + l == stones.back()) return true;
                    auto it = map.find(s + l);
                    if (it != map.end()) it->second.insert(l);
                }
            }
        }
        return false;
    }
};