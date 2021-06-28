#include "..\..\leetcode.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return {};

        vector<string> map {    // map[n]：数字n可以表示的所有字母
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> res;
        res.emplace_back("");
        for (char d : digits) {
            vector<string> cur;
            for (string& s : res) {
                string& chars = map[d - '0'];
                for (char c : chars) {
                    cur.emplace_back(s + c);
                }
            }
            res.swap(cur);
        }
        return res;
    }
};