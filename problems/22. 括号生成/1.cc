#include "..\..\leetcode.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        string s;
        function<void(int, int)> dfs = [&](int l, int r) {
            // l：可以使用的左括号数量，r：可以使用的右括号数量
            if (l == 0 && r == 0) {
                res.emplace_back(s);
                return;
            }
            if (l > 0) {
                s.push_back('(');
                dfs(l - 1, r);
                s.pop_back();
            }
            if (r > 0 && l < r) {
                s.push_back(')');
                dfs(l, r - 1);
                s.pop_back();
            }
        };
        dfs(n, n);
        return res;
    }
};