#include "..\..\leetcode.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            swap(nums[l], nums[l + rand() % (r - l + 1)]);
            int a = l, b = r + 1;
            int i = l + 1;
            while (i < b) {
                if (nums[i] > nums[l]) swap(nums[++a], nums[i++]);
                else if (nums[i] == nums[l]) i++;
                else swap(nums[--b], nums[i]);
            }
            swap(nums[l], nums[a]);
            if (k <= a) r = a - 1;
            else if (k <= b) break;
            else l = b;
        }
        return nums[k - 1];
    }
};