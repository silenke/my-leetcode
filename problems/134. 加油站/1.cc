#include "..\..\leetcode.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        const int n = gas.size();
        function<bool(int)> check = [&](int i) {
            int j = i;
            int g = 0;
            do {
                g += gas[j];
                if ((g -= cost[j]) < 0) return false;
                j = (j + 1) % n;
            } while (j != i);
            return true;
        };
        for (int i = 0; i < n; i++) {
            if (check(i)) return i;
        }
        return -1;
    }
};