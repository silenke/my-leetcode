#include "..\..\leetcode.h"

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {

        for (string& w : words) {
            reverse(w.begin(), w.end());
        }
        sort(words.begin(), words.end());
        int res = 0;
        for (int i = 1; i < words.size(); i++) {
            int size = words[i - 1].size();
            if (words[i - 1] != words[i].substr(0, size)) {
                res += size + 1;
            }
        }
        return res + words.back().size() + 1;
    }
};