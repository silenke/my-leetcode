#include "..\..\leetcode.h"

class Solution {
public:
    int findTheLongestSubstring(string s) {

        const char vowels[] = "aeiou";
        vector<int> map(1 << 5, INT_MAX);
        map[0] = -1;
        int res = 0;
        int state = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < 5; j++) {
                if (s[i] == vowels[j]) {
                    state ^= 1 << j;
                    break;
                }
            }
            res = max(res, i - map[state]);
            map[state] = min(map[state], i);
        }
        return res;
    }
};