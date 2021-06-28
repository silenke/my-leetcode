#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        if (s.empty()) return {};

        generate(s);

        int center = INT_MIN;
        int len = INT_MIN;
        int n = str.size();
        vector<int> r(n);
        int c = 0;
        r[c] = 1;
        for (int i = 0; i < n; i++) {
            r[i] = i >= c + r[c] ? 1 : min(r[c * 2 - i], c + r[c] - i);
            while (i + r[i] < n && i - r[i] >= 0) {
                if (str[i + r[i]] == str[i - r[i]])
                    r[i]++;
                else
                    break;
            }
            if (i + r[i] > c + r[c]) {
                c = i;
                if (r[i] > len) {
                    center = i;
                    len = r[i];
                }
            }
        }
        return s.substr((center - len + 1) / 2, len - 1);
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