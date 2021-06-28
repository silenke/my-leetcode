#include "..\..\leetcode.h"

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {

        if (hand.size() % W) return false;

        unordered_map<int, int> map;
        for (int n : hand) map[n]++;

        queue<int> q;
        for (auto [n, c] : map) {
            if (map.find(n - 1) == map.end()) q.push(n);
        }

        while (!q.empty()) {
            int s = q.front(); q.pop();
            for (int i = s + W - 1; i >= s; i--) {
                auto it = map.find(i);
                if (it == map.end()) return false;
                it->second -= map[s];
                if (it->second < 0) return false;
                if (it->second == 0) {
                    map.erase(it);
                    if (map.find(i + 1) != map.end()) q.push(i + 1);
                }
            }
        }
        return true;
    }
};