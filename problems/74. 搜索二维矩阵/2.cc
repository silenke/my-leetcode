#include "..\..\leetcode.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        const int m = matrix.size();
        const int n = matrix[0].size();

        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int num = matrix[mid / n][mid % n];
            if (target == num) return true;
            if (target < num) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};