#include "..\..\leetcode.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        const int m = matrix.size();
        if (m == 0) return 0;
        const int n = matrix[0].size();
        if (n == 0) return 0;

        int res = 0;
        vector<int> height(n);  // 向上可以取得的高度
        vector<int> left(n);    // 向左可以到达的位置
        vector<int> right(n, n - 1);   // 向右可以到达的位置
        for (int i = 0; i < m; i++) {

            int currLeft = 0;
            int currRight = n - 1;

            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                    left[j] = max(left[j], currLeft);
                }
                else {
                    height[j] = 0;
                    left[j] = 0;
                    currLeft = j + 1;
                }
            }

            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], currRight);
                }
                else {
                    right[j] = n - 1;
                    currRight = j - 1;
                }
            }

            for (int j = 0; j < n; j++) {
                res = max(res, height[j] * (right[j] - left[j] + 1));
            }
        }
        return res;
    }
};