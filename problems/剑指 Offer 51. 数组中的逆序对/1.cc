#include "..\..\leetcode.h"

class Solution {
public:
    int reversePairs(vector<int>& nums) {

        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int l ,int r) {
        
        if (l >= r) return 0;

        int mid = l + (r - l) / 2;
        return mergeSort(nums, l, mid) +
            mergeSort(nums, mid + 1, r) +
            merge(nums, l, mid, r);
    }

    int merge(vector<int>& nums, int l ,int mid, int r) {

        vector<int> tmp(r - l + 1);
        
        int res = 0;
        int i = l, j = mid + 1;
        int k = 0;
        while (i <= mid && j <= r) {
            if (nums[i] > nums[j]) {
                res += mid - i + 1;
                tmp[k++] = nums[j++];
            }
            else {
                tmp[k++] = nums[i++];
            }
        }
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }

        move(tmp.begin(), tmp.end(), nums.begin() + l);

        return res;
    }
};