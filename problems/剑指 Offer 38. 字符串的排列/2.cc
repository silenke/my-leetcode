#include "..\..\leetcode.h"

class Solution {
public:
    vector<string> permutation(string s) {

        sort(s.begin(), s.end());
        vector<string> res;
        string p;
        dfs(s, p, res);
        return res;
    }

private:
    void dfs(string& s, string& p, vector<string>& res) {

        if (p.size() == s.size()) {
            res.emplace_back(p);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '#' && (i == 0 || s[i - 1] != s[i])) {
                p.push_back(s[i]);
                s[i] = '#';
                dfs(s, p, res);
                s[i] = p.back();
                p.pop_back();
            }
        }
    }
};