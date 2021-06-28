#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        if (s.empty()) return {};

        int start = INT_MIN;
        int len = INT_MIN;
        for (int i = 0; i < s.size(); i++) {
            auto [start1, len1] = expandAroundCenter(s, i - 1, i + 1);
            auto [start2, len2] = expandAroundCenter(s, i, i + 1);
            if (len2 > len1) {
                start1 = start2;
                len1 = len2;
            }
            if (len1 > len) {
                start = start1;
                len = len1;
            }
        }
        return s.substr(start, len);
    }

private:
    pair<int, int> expandAroundCenter(const string& s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--;
            j++;
        }
        return {i + 1, j - i - 1}; // 最长回文串的起始位置，长度
    }
};