#include "..\..\leetcode.h"

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> map;
        for (const auto& edge : tickets) {
            map[edge[0]].emplace(edge[1]);
        }

        vector<string> res;
        function<void(const string&)> dfs = [&](const string& src) {
            auto& dess = map[src];
            while (!dess.empty()) {
                const string des = dess.top(); dess.pop();
                dfs(des);
            }
            res.emplace_back(src);
        };
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};