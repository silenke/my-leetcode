#include "..\..\leetcode.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        for (auto& edge : prerequisites) {
            graph[edge[1]].emplace_back(edge[0]);
        }

        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && dfs(graph, i, visited)) {
                return false;
            }
        }
        return true;
    }

private:
    bool dfs(const vector<vector<int>>& graph, int i, vector<int>& visited) {

        visited[i] = 1;
        for (int j : graph[i]) {
            if (!visited[j] && dfs(graph, j, visited) || visited[j] == 1) {
                return true;
            }
        }
        visited[i] = 2;
        return false;
    }
};