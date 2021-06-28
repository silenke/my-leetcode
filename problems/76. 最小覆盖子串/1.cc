#include "..\..\leetcode.h"

class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> map(128);
        for (char c : t) map[c]++;

        int minLen = INT_MAX, minLeft = -1;
        int count = t.size();
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            if (map[s[r]]-- > 0) count--;
            while (count == 0) {
                int len = r - l + 1;
                if (len < minLen) {
                    minLen = len;
                    minLeft = l;
                }
                if (++map[s[l++]] > 0) count++;
            }
        }
        return minLeft == -1 ? "" : s.substr(minLeft, minLen);
    }
};