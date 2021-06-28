#include "..\..\leetcode.h"

class Solution {
public:
    string reverseVowels(string s) {

        vector<bool> set(128);
        for (char c : "aeiouAEIOU") set[c] = true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!set[s[i]]) i++;
            else if (!set[s[j]]) j--;
            else swap(s[i++], s[j--]);
        }
        return s;
    }
};