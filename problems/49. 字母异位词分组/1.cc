#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> map;
        for (auto& s : strs) {
            string k(s);
            sort(k.begin(), k.end());
            map[k].emplace_back(s);
        }
        vector<vector<string>> res;
        for (auto& p : map) {
            res.emplace_back(p.second);
        }
        return res;
    }
};