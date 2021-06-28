#include "..\..\leetcode.h"

class Solution {
public:
    int trap(vector<int>& height) {

        if (height.size() < 3) return 0;
        int res = 0;
        int l = 0;
        int r = height.size() - 1;
        int maxl = height[l];
        int maxr = height[r];
        while (l < r) {
            if (maxl < maxr) {
                res += maxl - height[l];
                maxl = max(maxl, height[++l]);
            }
            else {
                res += maxr - height[r];
                maxr = max(maxr, height[--r]);
            }
        }
        return res;
    }
};