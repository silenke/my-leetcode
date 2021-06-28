#include "..\..\leetcode.h"

class NumArray {
public:
    NumArray(vector<int>& nums) : n(nums.size()), st(n * 2) {

        for (int i = n; i < n * 2; i++) {
            st[i] = nums[i - n];
        }
        for (int i = n - 1; i > 0; i--) {
            st[i] = st[i * 2] + st[i * 2 + 1];
        }
    }
    
    void update(int i, int val) {

        int diff = val - st[i + n];
        for (i += n; i > 0; i /= 2) {
            st[i] += diff;
        }
    }
    
    int sumRange(int i, int j) {

        int res = 0;
        for (i += n, j += n; i <= j; i /= 2, j /= 2) {
            if (i % 2 == 1) res += st[i++];
            if (j % 2 == 0) res += st[j--];
        }
        return res;
    }

private:
    int n;
    vector<int> st;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */