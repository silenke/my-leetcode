#include "..\..\leetcode.h"

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {

        if (hand.size() % W) return false;

        map<int, int> count;
        for (int n : hand) count[n]++;

        while (!count.empty()) {
            auto it = count.begin();
            int minNum = it->first;
            for (int i = 0; i < W; i++) {
                if (it->first != minNum + i) return false;
                if (--it->second == 0) count.erase(it);
                it++;
            }
        }
        return true;
    }
};