#include "..\..\leetcode.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return {};

        vector<string> res;
        string s;
        dfs(digits, s, res);
        return res;
    }

private:
    vector<string> map {    // map[n]：数字n可以表示的所有字母
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(const string& digits, string& s, vector<string>& res) {
        // 已经生成字符串s，将要查看字符digits[i]

        int i = s.size();

        if (i == digits.size()) {
            res.emplace_back(s);
            return;
        }

        string& chars = map[digits[i] - '0'];
        for (char c : chars) {
            s.push_back(c);
            dfs(digits, s, res);
            s.pop_back();
        }
    }
};