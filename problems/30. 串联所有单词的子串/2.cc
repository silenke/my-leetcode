#include "..\..\leetcode.h"

class Solution {
public:
    string reorganizeString(string S) {

        const int n = S.size();
        vector<int> map(128, 0);
        char maxC = 'a';
        for (char c : S) {
            map[c]++;
            if (map[c] > (n + 1) / 2) return "";
            if (map[c] > map[maxC]) maxC = c;
        }

        string res(n, ' ');
        int i = 0;
        while (map[maxC]-- > 0) {
            res[i] = maxC;
            i += 2;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            while (map[c]-- > 0) {
                if (i >= n) i = 1;
                res[i] = c;
                i += 2;
            }
        }
        return res;
    }
};