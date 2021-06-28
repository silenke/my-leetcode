#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;
        unordered_map<string, int> map;
        for (const string& s : strs) {
            string k(s);
            sort(k.begin(), k.end());
            auto it = map.find(k);
            if (it != map.end()) {
                res[it->second].emplace_back(s);
            }
            else {
                map[k] = res.size();
                res.push_back({s});
            }
        }
        return res;
    }
};