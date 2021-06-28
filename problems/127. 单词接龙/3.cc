#include "..\..\leetcode.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> set(wordList.begin(), wordList.end());
        if (set.find(endWord) == set.end()) return 0;

        unordered_set<string> s1{beginWord};
        unordered_set<string> s2{endWord};
        int step = 1;
        while (!s1.empty() && !s2.empty()) {
            step++;
            if (s1.size() > s2.size()) s1.swap(s2);
            unordered_set<string> tmp;
            for (string w : s1) {
                for (int i = 0; i < w.size(); i++) {
                    char c = w[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        if (s2.find(w) != s2.end()) return step;
                        if (set.find(w) != set.end()) {
                            tmp.insert(w);
                            set.erase(w);
                        }
                    }
                    w[i] = c;
                }
            }
            s1.swap(tmp);
        }
        return 0;
    }
};