#include <iostream>
#include <vector>

using namespace std;

// Time complexity: 
// Space complexity: 

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        col = vector<bool>(n, false);
        dia1 = vector<bool>(2 * n - 1, false);
        dia2 = vector<bool>(2 * n - 1, false);

        vector<int> q;
        putQueens(n, 0, q);

        return ans;
    }

private:
    vector<vector<string>> ans;
    vector<bool> col, dia1, dia2;

    void putQueens(int n, int row, vector<int> &q) {

        if (row == n) {
            ans.push_back(convert(n, q));
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!col[i] && !dia1[row + i] && !dia2[row - i + n - 1]) {
                q.push_back(i);
                col[i] = dia1[row + i] = dia2[row - i + n - 1] = true;
                putQueens(n, row + 1, q);
                q.pop_back();
                col[i] = dia1[row + i] = dia2[row - i + n - 1] = false;
            }
        }
    }

    vector<string> convert(int n, vector<int> &q) {

        vector<string> ret(n, string(n, '.'));
        for (int i = 0; i < n; i++)
            ret[i][q[i]] = 'Q';
        return ret;
    }
};

int main() {

    vector<vector<string>> ans = Solution().solveNQueens(4);
    for (auto &x : ans) {
        for (auto &y : x) {
            cout << y << endl;
        }
        cout << endl;
    }

    return 0;
}