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
        vector<P> intervals{ {0, 0} };
        for (int a : A) {
            vector<P> newIntervals;
            for (auto& i : intervals) {
                newIntervals.push_back({ i.first + a, i.second + a });
            }
            intervals = merge(intervals, newIntervals);
        }
        for (auto it = intervals.rbegin(); it != intervals.rend(); it++) {
            if ((*it).second < m) return (*it).second;
            if ((*it).first <= m && m <= (*it).second) return m;
        }
        return 0;
    }

private:
    typedef pair<int, int> P;

    vector<P> merge(vector<P>& a, vector<P>& b) {

        vector<P> res;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i].first < b[j].first) insert(res, a[i++]);
            else insert(res, b[j++]);
        }
        while (i < a.size()) insert(res, a[i++]);
        while (j < b.size()) insert(res, b[j++]);
        return res;
    }

    void insert(vector<P>& res, P& a) {

        if (res.empty() || a.first > res.back().second + 1) res.emplace_back(a);
        res.back().second = max(res.back().second, a.second);
    }
};