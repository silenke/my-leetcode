#include "..\..\leetcode.h"

class Solution {
public:
    vector<string> permutation(string s) {

        sort(s.begin(), s.end());
        vector<string> res;
        dfs(s, 0, res);
        return res;
    }

private:
    void dfs(string s, int i, vector<string>& res) {

        if (i == s.size() - 1) {
            res.emplace_back(s);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (i == j || s[i] != s[j]) {
                swap(s[i], s[j]);
                dfs(s, i + 1, res);
            }
        }
    }
};