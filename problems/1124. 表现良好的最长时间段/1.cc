#include "..\..\leetcode.h"

class Solution {
public:
    int longestWPI(vector<int>& hours) {

        unordered_map<int, int> map;    // map[s]：前缀和s最早出现的位置
        int res = 0;
        int sum = 0;
        for (int i = 0; i < hours.size(); i++) {
            sum += hours[i] > 8 ? 1 : -1;
            if (sum > 0) res = i + 1;
            else {
                res = max(res, s)
            }
        }
        return res;
    }
};