#include "..\..\leetcode.h"

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        if (s.empty()) return {};

        generate(s);
        
        int n = str.size();
        vector<int> len(n); // len[i]：以位置i为中心的最长回文串长度
        int res = 0;    // 最长回文串的中心位置
        int c = 0;  // 上次到达最右边界的中心位置
        len[c] = 1;
        for (int i = 1; i < n; i++) {
            int r = c + len[c]; // 最右边界
            len[i] = i >= r ? 1 : min(len[c * 2 - i], r - i);
            while (i + len[i] < n && i - len[i] >= 0) {
                if (str[i + len[i]] == str[i - len[i]])
                    len[i]++;
                else
                    break;
            }
            if (i + len[i] > r) {
                c = i;
                if (len[i] > len[res]) {
                    res = i;
                }
            }
        }
        return s.substr((res - len[res] + 1) / 2, len[res] - 1);
    }

private:
    string str;

    void generate(const string& s) {
        
        str.resize(s.size() * 2 + 1);
        for (int i = 0, j = 0; i < str.size(); i++) {
            str[i] = i & 1 ? s[j++] : '#';
        }
    }
};