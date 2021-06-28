#include "..\..\leetcode.h"

class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int> map(128, -1);   // map[c]：字符c最后出现的位置
        for (int i = 0; i < s.size(); i++) map[s[i]] = i;

        string res;
        vector<bool> used(128, false);
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (used[c]) continue;
            while (!res.empty() && res.back() > c && map[res.back()] > i) {
                used[res.back()] = false;
                res.pop_back();
            }
            res.push_back(c);
            used[c] = true;
        }
        return res;
    }
};