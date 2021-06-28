#include "..\..\leetcode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> map(128, -1);   // map[c]：字符c上次出现的位置
        int l = 0;  // 窗口左边界
        int res = 0;
        for (int r = 0; r < s.size(); r++) {
            l = max(l, map[s[r]] + 1);
            res = max(res, r - l + 1);
            map[s[r]] = r;
        }
        return res;
    }
};