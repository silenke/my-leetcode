#include "..\..\leetcode.h"

class Solution {
public:
    string longestPalindrome(string s) {
        
        string str;
        generate(str, s);

        int n = str.size();
        vector<int> radius(n);
        radius[0] = 1;
        int last = 0;
        int res = 0;
        for (int i = 1; i < n; i++) {
            int right = last + radius[last];
            radius[i] = i >= right ? 1 : min(radius[last * 2 - i], right - i);
            while (i - radius[i] >= 0 && i + radius[i] < n) {
                if (str[i - radius[i]] == str[i + radius[i]]) {
                    radius[i]++;
                }
                else break;
            }
            if (i + radius[i] > right) {
                last = i;
                if (radius[i] > radius[res]) {
                    res = i;
                }
            }
        }
        return s.substr((res - radius[res] + 1) / 2, radius[res] - 1);
    }

private:
    void generate(string& str, const string& s) {

        str.resize(s.size() * 2 + 1);
        for (int i = 0; i < str.size(); i++) {
            str[i] = i & 1 ? s[i / 2] : '#';
        }
    }
};