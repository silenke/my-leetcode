#include "..\..\leetcode.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        return quickSort(nums, 0, nums.size() - 1, k - 1);
    }

private:
    int quickSort(vector<int>& nums, int l, int r, int k) {
        
        if (l == r) return nums[l];

        swap(nums[l], nums[l + random() % (r - l + 1)]);

        int a = l;
        int b = r + 1;
        int i = l + 1;
        while (i < b) {
            if (nums[i] > nums[l]) swap(nums[++a], nums[i++]);
            else if (nums[i] == nums[l]) i++;
            else swap(nums[i], nums[--b]);
        }
        swap(nums[l], nums[a]);

        if (k < a) return quickSort(nums, l, a - 1, k);
        if (k < b) return nums[a];
        return quickSort(nums, b, r, k);
    }
};