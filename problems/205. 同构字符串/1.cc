#include "..\..\leetcode.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        vector<int> map1(128);
        vector<int> map2(128);

        for (int i = s.size() - 1; i >= 0; i--) {
            if (map1[s[i]] != map2[t[i]]) return false;
            map1[s[i]] = map2[t[i]] = i;
        }
        return true;
    }
};