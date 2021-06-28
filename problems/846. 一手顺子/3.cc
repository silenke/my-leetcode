#include "..\..\leetcode.h"

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {

        if (hand.size() % W) return false;

        unordered_map<int, int> map;
        for (int n : hand) map[n]++;

        queue<int> q;
        for (auto [n, c] : map) {
            if (map[n - 1] == 0) q.push(n);
        }

        while (!q.empty()) {
            int s = q.front(); q.pop();
            for (int i = s + W - 1; i >= s; i--) {
                map[i] -= map[s];
                if (map[i] < 0) return false;
                if (map[i] == 0 && map[i + 1] > 0) q.push(i + 1);
            }
        }
        return true;
    }
};