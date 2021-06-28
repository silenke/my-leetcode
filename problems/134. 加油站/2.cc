#include "..\..\leetcode.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int total = 0;
        int start = 0;
        int g = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            g += gas[i] - cost[i];
            if (g < 0) {
                start = i + 1;
                g = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};