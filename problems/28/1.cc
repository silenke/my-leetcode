#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle.empty()) return 0;

        generate(needle);
        int i = 0;
        int j = 0;
        while (i < haystack.size() && j < needle.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else if (j > 0) {
                j = next[j];
            }
            else {
                i++;
            }
        }
        return j == needle.size() ? i - j : -1;
    }

private:
    vector<int> next;

    void generate(const string& s) {
        
        if (s.size() == 1) return;

        next.resize(s.size());
        next[0] = -1;
        next[1] = 0;
        int cn = 0;
        int i = 2;
        while (i < s.size()) {
            if (s[cn] == s[i - 1]) {
                next[i++] = ++cn;
            }
            else if (cn > 0) {
                cn = next[cn];
            }
            else {
                next[i++] = 0;
            }
        }
    }
};