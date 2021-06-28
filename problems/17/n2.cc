#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return {};

        vector<string> map {    // 数字，可以表示的字符
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" 
        };

        vector<string> res; // 上次的结果
        res.emplace_back("");
        for (char d : digits) {
            vector<string> tmp; // 当前的结果
            for (string& s : res) {
                string& chars = map[d - '0'];
                for (char c : chars) {
                    tmp.emplace_back(s + c);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};