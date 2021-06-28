#include "..\..\leetcode.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        const int n = nums.size();
        for (int i = n / 2; i >= 0; i--) {
            shiftDown(nums, n, i);
        }
        for (int i = 0; i < k - 1; i++) {
            nums[0] = nums[n - i - 1];
            shiftDown(nums, n - i - 1, 0);
        }
        return nums[0];
    }

private:
    void shiftDown(vector<int>& nums, int n, int i) {
        
        int tmp = nums[i];
        while (i * 2 + 1 < n) {
            int j = i * 2 + 1;
            if (j + 1 < n && nums[j + 1] > nums[j]) j++;
            if (nums[j] <= tmp) break;
            nums[i] = nums[j];
            i = j;
        }
        nums[i] = tmp;
    }
};