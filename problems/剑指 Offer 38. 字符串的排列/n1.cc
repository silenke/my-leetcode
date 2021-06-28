#include "..\..\leetcode.h"

class Solution {
public:
    vector<string> permutation(string s) {

        vector<string> res;
        function<void(int)> dfs = [&](int i) {
            if (i == s.size() - 1) {
                res.emplace_back(s);
                return;
            }
            for (int j = i; j < s.size(); j++) {
                bool valid = true;
                for (int k = i; k < j; k++) {
                    if (s[k] == s[j]) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) continue;
                swap(s[i], s[j]);
                dfs(i + 1);
                swap(s[i], s[j]);
            }
        };
        dfs(0);
        return res;
    }
};