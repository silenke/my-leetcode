#include "..\..\leetcode.h"

class Solution {
public:
    string reverseWords(string s) {

        reverse(s.begin(), s.end());
        auto i = s.begin();     // 单词开头
        auto insert = s.begin();  // 等待插入的位置
        while (i < s.end()) {
            while (i < s.end() && *i == ' ') i++;
            if (i == s.end()) break;
            auto j = i + 1;     // 单词结尾（左闭右开）
            while (j < s.end() && *j != ' ') j++;
            reverse(i, j);
            move(i, j + 1, insert);
            insert += j - i + 1;
            i = j + 1;
        }
        s.erase(max(s.begin(), insert - 1), s.end());
        return s;
    }
};