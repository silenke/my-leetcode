#include "..\..\leetcode.h"

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> counts(128, 0);
        for (char c : tasks) counts[c]++;
        int max_count = *max_element(counts.begin(), counts.end());
        int res = (max_count - 1) * (n + 1);
        res += count_if(counts.begin(), counts.end(),
            [&](int c){ return c == max_count; });
        return max(res, static_cast<int>(tasks.size()));
    }
};