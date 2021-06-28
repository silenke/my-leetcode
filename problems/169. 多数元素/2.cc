#include "..\..\leetcode.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        return partition(nums, 0, nums.size() - 1);
    }

private:
    int partition(vector<int>& nums, int l, int r) {
        
        if (l >= r) return nums[l];

        swap(nums[l], nums[l + rand() % (r - l + 1)]);
        int p = l;
        int q = r + 1;
        int i = l + 1;
        while (i < q) {
            if (nums[i] < nums[l]) swap(nums[++p], nums[i++]);
            else if (nums[i] == nums[l]) i++;
            else swap(nums[i], nums[--q]);
        }
        swap(nums[l], nums[p]);

        int mid = l + (r - l) / 2;
        if (mid < p) return partition(nums, l, p);
        if (mid >= q) return partition(nums, q, r);
        return nums[mid];
    }
};