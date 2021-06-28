#include "..\..\leetcode.h"

class Solution {
public:
    int reversePairs(vector<int>& nums) {

        int res = 0;
        vector<int> tmp(nums.size());
        function<void(int, int)> mergeSort = [&](int l, int r) {
            if (l >= r) return;
            int m = l + (r - l) / 2;
            mergeSort(l, m);
            mergeSort(m + 1, r);
            int i = l, j = m + 1;
            int k = l;
            while (i <= m && j <= r) {
                if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
                else tmp[k++] = nums[j++], res += m - i + 1;
            }
            while (i <= m) tmp[k++] = nums[i++];
            while (j <= r) tmp[k++] = nums[j++];
            move(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        };
        mergeSort(0, nums.size() - 1);
        return res;
    }
};