#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        const int wordSize = words[0].size();
        const int wordsNum = words.size();

        unordered_map<string, int> m1;
        for (const string& w : words) m1[w]++;

        vector<int> res;
        for (int i = 0; i < wordSize; i++) {
            unordered_map<string, int> m2;
            int count = 0;
            int l = i;
            for (int r = i; r + wordSize <= s.size(); r += wordSize) {
                string w = s.substr(r, wordSize);
                if (m1.find(w) == m1.end()) {
                    m2.clear();
                    count = 0;
                    l = r + wordSize;
                }
                else {
                    m2[w]++;
                    count++;
                    while (m2[w] > m1[w]) {
                        m2[s.substr(l, wordSize)]--;
                        count--;
                        l += wordSize;
                    }
                    if (count == wordsNum) res.emplace_back(l);
                }
            }
        }
        return res;
    }
};