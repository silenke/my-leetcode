#include "..\..\leetcode.h"

class Solution {
public:
    string sortString(string s) {
        
        vector<int> counts(128, 0);
        for (char c : s) counts[c]++;

        string res;
        while (res.size() < s.size()) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (counts[c]-- > 0) res.push_back(c);
            }
            for (char c = 'z'; c >= 'a'; c--) {
                if (counts[c]-- > 0) res.push_back(c);
            }
        }
        return res;
    }
};