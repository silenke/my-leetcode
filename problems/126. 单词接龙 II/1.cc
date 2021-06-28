#include "..\..\leetcode.h"

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> set(wordList.begin(), wordList.end());
        if (!set.count(endWord)) return {};

        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> steps;
        queue<string> q;
        q.emplace(beginWord);
        set.erase(beginWord);
        set.erase(endWord);
        parents[beginWord].emplace_back();
        int step = 0;
        bool found = false;
        while (!q.empty() && !found) {
            step++;
            for (int n = q.size(); n > 0; n--) {
                string parent = q.front(); q.pop();
                string child = parent;
                for (char& i : child) {
                    const char c = i;
                    for (char j = 'a'; j <= 'z'; j++) {
                        i = j;
                        if (child == endWord) {
                            parents[child].emplace_back(parent);
                            found = true;
                        }
                        else if (steps.count(child) && step < steps[child]) {
                            parents[child].emplace_back(parent);
                        }
                        if (!set.count(child)) continue;
                        q.emplace(child);
                        set.erase(child);
                        parents[child].emplace_back(parent);
                        steps[child] = step + 1;
                    }
                    i = c;
                }
            }
        }

        if (!found) return {};

        vector<vector<string>> res;
        vector<string> path;
        string curr = endWord;
        function<void(const string&)> dfs = [&](const string& curr) {
            if (curr == "") {
                res.emplace_back(path.rbegin(), path.rend());
                return;
            }
            path.emplace_back(curr);
            for (const string& s : parents[curr]) {
                dfs(s);
            }
            path.pop_back();
        };
        dfs(curr);
        return res;
    }
};