#include "..\..\leetcode.h"

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> print(vector<vector<int>>& matrix) {
        
        vector<int> res;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i1 = 0, j1 = 0;
        int i2 = 0, j2 = 0;
        
        bool fromUp = false;
        while (i1 < m) {
            int k = i2 - i1 + 1;
            for (int i = 0; i < k; i++) {
                if (fromUp) {
                    res.emplace_back(matrix[i1 + i][j1 - i]);
                }
                else {
                    res.emplace_back(matrix[i2 - i][j2 + i]);
                }
            }
            if (j1 < n - 1) j1++;
            else i1++;
            if (i2 < m - 1) i2++;
            else j2++;
            fromUp = !fromUp;
        }
        return res;
    }
};

int main() {
    
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    vector<int> res = Solution().print(matrix);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    
    return 0;
}