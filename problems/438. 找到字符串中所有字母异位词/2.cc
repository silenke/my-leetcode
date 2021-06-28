#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> mp(128);
        for (char c : p) mp[c]++;

        vector<int> res;
        vector<int> ms(128);
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            ms[s[r]]++;
            while (ms[s[r]] > mp[s[r]]) {
                ms[s[l++]]--;
            }
            if (r - l + 1 == p.size()) {
                res.emplace_back(l);
            }
        }
        return res;
    }
};