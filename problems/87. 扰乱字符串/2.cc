#include "..\..\leetcode.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {

        if (s1.size() != s2.size()) return false;

        function<bool(int, int, int)> dfs = [&](int i, int j, int l) {
            if (l == 1) return s1[i] == s2[j];

            vector<int> map(128);
            for (int k = 0; k < l; k++) {
                map[s1[i + k]]++;
                map[s2[j + k]]--;
            }
            for (int m : map) {
                if (m) return false;
            }

            for (int k = 1; k < l; k++) {
                if (dfs(i, j, k) && dfs(i + k, j + k, l - k)) return true;
                if (dfs(i, j + l - k, k) && dfs(i + k, j, l - k)) return true;
            }
            return false;
        };
        return dfs(0, 0, s1.size());
    }
};