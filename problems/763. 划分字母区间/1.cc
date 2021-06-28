#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> partitionLabels(string S) {

        const int n = S.size();
        vector<int> map(128, -1);
        for (int i = 0; i < n; i++) {
            map[S[i]] = i;
        }
        vector<int> res;
        int l = 0;
        int r = 0;
        for (int i = 0; i < n; i++) {
            r = max(r, map[S[i]]);
            if (i == r) {
                res.push_back(r - l + 1);
                l = r + 1;
            }
        }
        return res;
    }
};