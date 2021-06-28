#include "..\..\leetcode.h"

class Solution {
public:
    int strStr(string haystack, string needle) {

        int m = haystack.size();
        int n = needle.size();

        vector<int> next(n);
        generate(needle, next);

        int i = 0, j = 0;
        while (i < m && j < n) {
            if (haystack[i] == needle[j]) { i++; j++; }
            else if (j > 0) j = next[j];
            else i++;
        }
        return j == n ? i - j : -1;
    }

private:
    void generate(const string& needle, vector<int>& next) {
        
        if (needle.size() < 2) return;

        next[0] = -1;
        next[1] = 0;
        int i = 2, j = 0;
        while (i < needle.size()) {
            if (needle[j] == needle[i - 1]) next[i++] = ++j;
            else if (j > 0) j = next[j];
            else next[i++] = 0;
        }
    }
};