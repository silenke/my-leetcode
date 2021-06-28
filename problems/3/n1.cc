#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        const int n = s.size();

        vector<int> map(128, -1);   // 字符，上次出现的位置
        int res = 0;
        for (int l = 0, i = 0; i < n; i++) {
            l = max(l, map[s[i]] + 1);
            res = max(res, i - l + 1);
            map[s[i]] = i;
        }
        return res;
    }
};