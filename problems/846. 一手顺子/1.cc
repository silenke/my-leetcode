#include "..\..\leetcode.h"

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {

        if (hand.size() % W) return false;

        map<int, int> count;
        for (int n : hand) count[n]++;

        while (!count.empty()) {
            int minNum = count.begin()->first;
            for (int i = 0; i < W; i++) {
                auto it = count.find(minNum + i);
                if (it == count.end()) return false;
                if (--it->second == 0) count.erase(it);
            }
        }
        return true;
    }
};