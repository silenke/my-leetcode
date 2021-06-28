#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        const int n = nums.size();
        function<int(int)> search = [&](int t) {
            int l = 0, r = n;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (nums[m] > t) r = m;
                else l = m + 1;
            }
            return l;
        };
        int s = search(target - 1);
        if (s == n || nums[s] != target) return {-1, -1};
        return {s, search(target) - 1};
    }
};