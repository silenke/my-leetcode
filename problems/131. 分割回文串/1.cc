#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<string>> partition(string s) {

        const int n = s.size();
        vector<vector<bool>> valid(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                valid[l--][r++] = true;
            }
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                valid[l--][r++] = true;
            }
        }

        vector<vector<string>> res;
        vector<string> r;
        function<void(int)> dfs = [&](int i) {
            // r存放已经得到的子串，从位置i开始寻找新的子串
            if (i == n) {
                res.emplace_back(r);
                return;
            }
            for (int j = i; j < n; j++) {
                if (valid[i][j]) {
                    r.emplace_back(move(s.substr(i, j - i + 1)));
                    dfs(j + 1, r);
                    r.pop_back();
                }
            }
        };
        dfs(0, r);
        return res;
    }
};