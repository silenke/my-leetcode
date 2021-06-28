#include "..\..\leetcode.h"

class NumArray {
public:
    NumArray(vector<int>& nums) : nums_(std::move(nums)), sums_(nums_.size() + 1){

        for (int i = 1; i <= nums_.size(); i++) {
            update_(i, nums_[i - 1]);
        }
    }
    
    void update(int index, int val) {

        update_(index + 1, val - nums_[index]);
        nums_[index] = val;
    }
    
    int sumRange(int left, int right) {

        return query(right + 1) - query(left);
    }

private:
    vector<int> nums_;
    vector<int> sums_;  // sums_[i]：前i个元素的和

    int lowbit(int x) {
        return x & (-x);
    }

    int query(int i) {
        int res = 0;
        while (i > 0) {
            res += sums_[i];
            i -= lowbit(i);
        }
        return res;
    }

    void update_(int i, int val) {
        while (i < sums_.size()) {
            sums_[i] += val;
            i += lowbit(i);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums_);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */