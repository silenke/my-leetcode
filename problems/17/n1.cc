#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return {};
        
        res.clear();
        string s;
        dfs(digits, 0, s);
        return res;
    }

private:
    vector<string> res;
    vector<string> map {    // 数字，可以表示的字符
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" 
    };

    void dfs(const string& digits, int i, string& s) {
        // i：要处理的数字的索引，s：已经得到的字符串
        if (i == digits.size()) {
            res.push_back(s);
            return;      
        }

        string& chars = map[digits[i] - '0'];
        for (char c : chars) {
            s.push_back(c);
            dfs(digits, i + 1, s);
            s.pop_back();
        }
    }
};