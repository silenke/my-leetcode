#include "..\..\leetcode.h"

class Solution {
public:
    vector<string> permutation(string s) {

        sort(s.begin(), s.end());
        vector<string> res;
        const int n = s.size();
        string p(n, ' ');
        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                res.emplace_back(p);
                return;
            }
            for (int j = 0; j < n; j++) {
                if (s[j] == '#') continue;
                if (j > 0 && s[j] == s[j - 1]) continue;
                p[i] = s[j];
                s[j] = '#';
                dfs(i + 1);
                s[j] = p[i];
            }
        };
        dfs(0);
        return res;
    }
};