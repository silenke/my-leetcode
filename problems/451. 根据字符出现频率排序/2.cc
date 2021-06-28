#include "..\..\leetcode.h"

class Solution {
public:
    string frequencySort(string s) {

        vector<int> counts(128);
        for (char c : s) counts[c]++;

        vector<pair<int, char>> p;
        for (char c = 0; c < counts.size(); c++) {
            p.emplace_back(counts[c], c);
        }

        sort(p.rbegin(), p.rend());

        string res;
        for (auto [count, c] : p) {
            res.append(count, c);
        }
        return res;
    }
};