#include "..\..\leetcode.h"

class Tree {
public:
    Tree(int size) : sums(size + 1, 0) {}

    void update(int i, int val) {
        while (i < sums.size()) {
            sums[i] += val;
            i += lowbit(i);
        }
    }

    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += sums[i];
            i -= lowbit(i);
        }
        return res;
    }

private:
    vector<int> sums;
    
    int lowbit(int x) {
        return x & (-x);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {

        set<int> sorted(nums.begin(), nums.end());

        unordered_map<int, int> ranks;
        int r = 1;
        for (int n : sorted) {
            ranks[n] = r++;
        }

        vector<int> res(nums.size());
        Tree tree(ranks.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] = tree.query(ranks[nums[i]] - 1);
            tree.update(ranks[nums[i]], 1);
        }
        return res;
    }
};