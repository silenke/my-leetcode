#include "..\..\leetcode.h"

class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<int> map1(128);  // map1[c]：字符c上次出现的位置+1
        unordered_map<string, int> map2;    // map2[w]：单词w上次出现的位置+1

        int i = 0, j = 0;
        while (i < pattern.size() && j < s.size()) {
            string word;
            while (j < s.size() && s[j] != ' ') {
                word.push_back(s[j++]);
            }
            if (map1[pattern[i]] != map2[word]) return false;
            map1[pattern[i]] = map2[word] = i + 1;
            i++, j++;
        }
        return i >= pattern.size() && j > s.size();
    }
};