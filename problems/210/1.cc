#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        for (auto& edge : prerequisites) {
            graph[edge[1]].emplace_back(edge[0]);
        }

        stack<int> s;
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && dfs(graph, i, visited, s)) {
                return {};
            }
        }
        
        vector<int> res;
        while (!s.empty()) {
            res.emplace_back(s.top()); s.pop();
        }
        return res;
    }

private:
    bool dfs(const vector<vector<int>>& graph, int i, vector<int>& visited, stack<int>& s) {

        visited[i] = 1;
        for (int j : graph[i]) {
            if (!visited[j] && dfs(graph, j, visited, s) || visited[j] == 1) {
                return true;
            }
        }
        s.emplace(i);
        visited[i] = 2;
        return false;
    }
};