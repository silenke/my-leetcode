#include "..\..\leetcode.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        const int n = nums.size();
        for (int i = (n - 2) / 2; i >= 0; i--) {
            shiftDown(nums, n - 1, i);
        }

        for (int i = 0; i < k - 1; i++) {
            nums[0] = nums[n - 1 - i];
            shiftDown(nums, n - 1 - i, 0);
        }
        return nums[0];
    }

private:
    void shiftDown(vector<int>& nums, int n, int i) {

        int k = nums[i];
        while (i * 2 + 1 <= n) {
            int l = i * 2 + 1;
            if (l + 1 <= n && nums[l + 1] > nums[l]) l++;
            if (k >= nums[l]) break;
            nums[i] = nums[l];
            i = l;
        }
        nums[i] = k;
    }
};