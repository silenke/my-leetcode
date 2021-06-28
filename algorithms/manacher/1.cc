#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int manacher(const string& str) {

        if (str.empty())
            return {};

        generate(str);

        vector<int> pArr(s.size());
        int C = -1;
        int R = -1;
        int res = INT_MIN;
        for (int i = 0; i < s.size(); i++) {
            pArr[i] = i > R ? 1 : min(pArr[C * 2 - i], R - i);
            while (i + pArr[i] < s.size() && i - pArr[i] >= 0) {    // 没有越界
                if (s[i + pArr[i]] == s[i - pArr[i]]) {
                    pArr[i]++;  // 扩大边界
                }
                else {
                    break;
                }
            }
            if (i + pArr[i] > R) {
                R = i + pArr[i];
                C = i;
            }
            res = max(res, pArr[i]);
        }
        return res - 1;
    }

private:
    string s;

    void generate(const string& str) {

        s.clear();
        s.reserve(str.size() * 2 + 1);
        for (int i = 0, j = 0; i < s.size(); i++) {
            s[i] = i & 1 ? str[j++] : '#';
        }
    }
};