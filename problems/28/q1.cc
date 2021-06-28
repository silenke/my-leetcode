#include "..\..\leetcode.h"

class Solution {
public:
    int strStr(string haystack, string needle) {

        const int m = haystack.size();
        const int n = needle.size();

        vector<int> next(n);
        generate(needle, next);

        int i = 0, j = 0;
        while (i < m && j < n) {
            if (haystack[i] == needle[j]) i++, j++;
            else if (j > 0) j = next[j];
            else i++;
        }
        return j == n ? i - j : -1;
    }

private:
    void generate(const string& s, vector<int>& next) {

        if (s.size() < 2) return;
        
        int i = 2, j = 0;   // j：当前最长前缀的长度
        while (i < s.size()) {
            if (s[j] == s[i - 1]) next[i++] = ++j;
            else if (j > 0) j = next[j];
            else next[i++] = 0;
        }
    }
};