#include "..\..\leetcode.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return {};

        vector<string> map{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> res;
        res.emplace_back("");
        for (char d : digits) {
            vector<string> tmp;
            string& chars = map[d - '0'];
            for (char c : chars) {
                for (string& s : res) {
                    tmp.emplace_back(s + c);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};