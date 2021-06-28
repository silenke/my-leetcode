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

        set<int> sorted(nums.begin(), nums.end());
        unordered_map<int, int> ranks;
        int r = 1;
        for (int n : sorted) ranks[n] = r++;

        int res = 0;
        BIT bit(ranks.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            res += bit.query(ranks[nums[i]] - 1);
            bit.update(ranks[nums[i]], 1);
        }
        return res;
    }
};