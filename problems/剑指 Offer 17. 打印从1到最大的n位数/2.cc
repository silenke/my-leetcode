#include "..\..\leetcode.h"

class Solution {
public:
    vector<string> printNumbers(int n) {

        vector<string> res;
        string s(n, ' ');
        int l = n - 1;  // 有效字符开始的位置
        function<void(int, int)> dfs = [&](int i, int c) {
            // 将要处理字符串的i位，c是字符串已经包含的'9'的个数
            if (i == n) {
                if (l == n - 1 && s[n - 1] == '0') return;
                res.emplace_back(s.begin() + l, s.end());
                if (l + c == n) l--;
                return;
            }
            for (int j = '0' + (i == 0); j <= '9'; j++) {
                if (j == '9') c++;
                s[i] = j;
                dfs(i + 1, c);
            }
        };
        dfs(0, 0);
        for (const auto& s : res) {
            cout << s << endl;
        }
        return res;
    }
};