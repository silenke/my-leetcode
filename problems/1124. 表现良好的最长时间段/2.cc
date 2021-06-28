#include "..\..\leetcode.h"

class Solution {
public:
    int longestWPI(vector<int>& hours) {

        vector<int> map(hours.size() + 2, INT_MAX);
        int res = 0;
        int sum = 0;
        for (int i = 0; i < hours.size(); i++) {
            sum += hours[i] > 8 ? 1 : -1;
            if (sum > 0) res = i + 1;
            else {
                res = max(res, i - map[-sum + 1]);
                map[-sum] = min(map[-sum], i);
            }
        }
        return res;
    }
};