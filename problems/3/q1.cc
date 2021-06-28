#include "..\..\leetcode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> map(128, -1);
        int l = -1; // 当前窗口为(l,i]
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            l = max(l, map[s[i]]);
            res = max(res, i - l);
            map[s[i]] = i;
        }
        return res;
    }
};