#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        const int primes[26]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
            41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
        const int mod = 1e9 + 7;

        vector<vector<string>> res;
        unordered_map<int, int> map;
        for (const string& s : strs) {
            long k = 1;
            for (char c : s) {
                k *= primes[c - 'a'];
                k %= mod;
            }
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