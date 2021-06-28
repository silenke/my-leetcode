#include "..\..\leetcode.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> set(wordList.begin(), wordList.end());
        if (set.find(endWord) == set.end()) return 0;

        queue<string> q;
        q.emplace(beginWord);
        int step = 1;
        while (!q.empty()) {
            step++;
            int n = q.size();
            while (n--) {
                string w = q.front(); q.pop();
                for (char i = 0; i < w.size(); i++) {
                    char c = w[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        if (set.find(w) != set.end()) {
                            if (w == endWord) return step;
                            q.emplace(w);
                            set.erase(w);
                        }
                    }
                    w[i] = c;
                }
            }
        }
        return 0;
    }
};