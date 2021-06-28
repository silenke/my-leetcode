#include <queue>
#include <iostream>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    int numSquares(int n) {

        queue<pair<int, int>> q;
        vector<bool> visited(n + 1, false);
        q.push(make_pair(n, 0));
        visited[n] = true;
        while (!q.empty()) {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            for (int i = 1;; i++) {
                int next = num - i * i;
                if (next < 0)
                    break;
                if (next == 0)
                    return step + 1;
                if (!visited[next]) {
                    q.push(make_pair(next, step + 1));
                    visited[next] = true;
                }
            }
        }

        return -1;
    }
};

int main() {

    cout << Solution().numSquares(12) << endl;

    return 0;
}