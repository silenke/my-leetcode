#include "..\..\leetcode.h"

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {

        int l = 0;
        int r = 0;
        for (char c : s) {
            if (c == '(') ++l;
            else if (c == ')') {
                if (l > 0) --l;
                else ++r;
            }
        }

        vector<string> res;
        dfs(s, 0, l, r, res);
        return res;
    }

private:
    bool isValid(const string& s) {
        
        int l = 0;
        for (char c : s) {
            if (c == '(') ++l;
            if (c == ')') --l;
            if (l < 0) return false;
        }
        return l == 0;
    }

    void dfs(const string& s, int i, int l, int r, vector<string>& res) {

        if (l == 0 && r == 0) {
            if (isValid(s)) res.emplace_back(s);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (j > i && s[j] == s[j - 1]) continue;
            if (s[j] == '(' || s[j] == ')') {
                string next(s);
                next.erase(j, 1);
                if (r > 0 && s[j] == ')') {
                    dfs(next, j, l, r - 1, res);
                }
                else if (l > 0 && s[j] == '(') {
                    dfs(next, j, l - 1, r, res);
                }
            }
        }
    }
};