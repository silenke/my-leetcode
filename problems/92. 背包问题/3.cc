#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int>& A) {
        // write your code here
        vector<vector<int>> intervals{ {0, 0} };
        for (int a : A) {
            vector<vector<int>> newIntervals;
            for (auto& i : intervals) {
                newIntervals.push_back({ i[0] + a, i[1] + a });
            }
            intervals = merge(intervals, newIntervals);
        }
        for (auto it = intervals.rbegin(); it != intervals.rend(); it++) {
            if ((*it)[1] < m) return (*it)[1];
            if ((*it)[0] <= m && m <= (*it)[1]) return m;
        }
        return 0;
    }

private:
    vector<vector<int>> merge(vector<vector<int>>& a, vector<vector<int>>& b) {

        vector<vector<int>> res;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i][0] < b[j][0]) insert(res, a[i++]);
            else insert(res, b[j++]);
        }
        while (i < a.size()) insert(res, a[i++]);
        while (j < b.size()) insert(res, b[j++]);
        return res;
    }

    void insert(vector<vector<int>>& res, vector<int>& a) {

        if (res.empty() || a[0] > res.back()[1] + 1) res.emplace_back(a);
        res.back()[1] = max(res.back()[1], a[1]);
    }
};