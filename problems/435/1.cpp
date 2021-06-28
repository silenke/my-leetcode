#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Time complexity: O(n^2)
// Space complexity: O(n)

bool compare(const vector<int> &a, const vector<int> &b) {

    return a[0] <= b[0];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), compare);

        vector<int> dp(intervals.size(), 1);
        for (int i = 1; i < intervals.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (intervals[j][1] <= intervals[i][0])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        int ans = 0;
        for (int x : dp)
            ans = max(ans, x);
        return intervals.size() - ans;
    }
};

int main() {

    return 0;
}