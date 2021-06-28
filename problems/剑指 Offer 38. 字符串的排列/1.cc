#include "..\..\leetcode.h"

class Solution {
public:
    vector<string> permutation(string s) {

        vector<string> res;
        dfs(s, 0, res);
        return res;
    }

private:
    void dfs(string& s, int i, vector<string>& res) {

        if (i == s.size() - 1) {
            res.emplace_back(s);
            return;
        }

        unordered_set<int> set;
        for (int j = i; j < s.size(); j++) {
            if (set.find(s[j]) == set.end()) {
                set.insert(s[j]);
                swap(s[i], s[j]);
                dfs(s, i + 1, res);
                swap(s[j], s[i]);
            }
        }
    }
};