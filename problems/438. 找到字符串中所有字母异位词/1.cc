#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> mp(26, 0);
        for (char c : p) mp[c - 'a']++;

        vector<int> res;
        vector<int> ms(26, 0);
        for (int i = 0; i < s.size(); i++) {
            ms[s[i] - 'a']++;
            int l = i - p.size() + 1;
            if (l >= 0) {
                if (ms == mp) res.push_back(l);
                ms[s[l] - 'a']--;
            }
        }
        return res;
    }
};