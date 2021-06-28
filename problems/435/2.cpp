#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Time complexity: O(n^2)
// Space complexity: O(n)

bool compare(const vector<int> &a, const vector<int> &b) {

    return a[1] <= b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(), compare);

        int ans = 1;
        int pre = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[pre][1] <= intervals[i][0]) {
                ans++;
                pre = i;
            }
        }

        return intervals.size() - ans;
    }
};

int main() {

    return 0;
}