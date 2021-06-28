#include "..\..\leetcode.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);
        for (auto& edge : prerequisites) {
            graph[edge[1]].emplace_back(edge[0]);
        }

        vector<int> visited(numCourses, false);
        vector<int> onpath(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && dfs(graph, i, visited, onpath)) {
                return false;
            }
        }
        return true;
    }

private:
    bool dfs(const vector<vector<int>>& graph, int i, vector<int>& visited, vector<int>& onpath) {
        
        visited[i] = true;
        onpath[i] = true;
        for (int j : graph[i]) {
            if (!visited[j] && dfs(graph, j, visited, onpath) || onpath[j]) {
                return true;
            }
        }
        onpath[i] = false;
        return false;
    }
};