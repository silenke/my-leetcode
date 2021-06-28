#include "..\..\leetcode.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

        const int n = s.size();
        vector<string> res;
        function<void(int, int, string)> dfs = [&](int i, int j, string p) {
            if (i == n && j == 0) {
                p.pop_back();
                res.emplace_back(p);
                return;
            }
            if (i == n || j == 0) return;
            if (n - i > j * 3) return;
            int num = 0;
            for (int k = 1; k <= 3; k++) {
                if (i + k - 1 == n) return;
                if (s[i] == '0' && k > 1) return;
                num = num * 10 + s[i + k - 1] - '0';
                if (num > 255) return;
                dfs(i + k, j - 1, p + s.substr(i, k) + '.');
            }
        };
        dfs(0, 4, "");
        return res;
    }
};