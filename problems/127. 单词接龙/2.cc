#include "..\..\leetcode.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> set(wordList.begin(), wordList.end());
        if (set.find(endWord) == set.end()) return 0;

        unordered_map<string, int> map;
        map[beginWord] = -1;

        queue<string> q;
        q.emplace(beginWord);
        int step = 1;
        while (!q.empty()) {
            step++;
            int n = q.size();
            while (n--) {
                string w = q.front(); q.pop();
                int last = map[w];
                for (char i = 0; i < w.size(); i++) {
                    if (i == last) continue;
                    char c = w[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        if (set.find(w) != set.end()) {
                            if (w == endWord) return step;
                            q.emplace(w);
                            set.erase(w);
                            map[w] = i;
                        }
                    }
                    w[i] = c;
                }
            }
        }
        return 0;
    }
};