#include "..\..\leetcode.h"

class BIT {
public:
    BIT(int n) : sums(n + 1) {}

    int query(int i) {

        int res = 0;
        while (i > 0) {
            res += sums[i];
            i -= lowbit(i);
        }
        return res;
    }

    void update(int i, int val) {

        while (i < sums.size()) {
            sums[i] += val;
            i += lowbit(i);
        }
    }

private:
    vector<int> sums;

    int lowbit(int i) { return i & -i; }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {

        vector<int> ranks(nums);
        sort(nums.begin(), nums.end());
        for (int& n : ranks) {
            n = lower_bound(nums.begin(), nums.end(), n) - nums.begin() + 1;
        }

        int res = 0;
        BIT bit(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            res += bit.query(ranks[i] - 1);
            bit.update(ranks[i], 1);
        }
        return res;
    }
};