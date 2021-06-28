#include "..\..\leetcode.h"

class NumArray {
public:
    NumArray(vector<int>& nums) : sums_(nums.size() + 1) {

        for (int i = 1; i <= nums.size(); i++) {
            sums_[i] = sums_[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int i, int j) {

        return sums_[j + 1] - sums_[i];
    }

private:
    vector<int> sums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */