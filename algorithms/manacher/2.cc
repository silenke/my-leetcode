#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mancher(const string& str) {
        
        if (str.empty()) {
            return 0;
        }

        generate(str);

        vector<int> pArr(s.size());
        int C = -1;
        int R = 0;
        int res = INT_MIN;
        for (int i = 0; i < s.size(); i++) {
            pArr[i] = i >= R ? 1 : min(pArr[C * 2 - i], R - i);
            while (i + pArr[i] < s.size() && i - pArr[i] >= 0) {
                if (s[i + pArr[i]] == s[i - pArr[i]]) {
                    pArr[i]++;
                }
                else {
                    break;
                }
            }   // 其实，R = C + pArr[C]
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

        s.resize(str.size() * 2 + 1);
        for (int i = 0, j = 0; i < s.size(); i++) {
            s[i] = i & 1 ? str[j++] : '#';
        }
    }
};