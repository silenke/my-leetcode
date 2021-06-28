#include "..\..\leetcode.h"

class Solution {
public:
    string frequencySort(string s) {

        vector<int> counts(128);
        for (char c : s) counts[c]++;

        vector<int> chars(128);
        iota(chars.begin(), chars.end(), 0);
        sort(chars.begin(), chars.end(),
            [&](char a, char b){ return counts[a] > counts[b]; }
        );
        string res;
        for (char c : chars) {
            res.append(counts[c], c);
        }
        return res;
    }
};