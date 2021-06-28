#include "..\..\leetcode.h"

class Solution { 
public:
    long long sum(vector<int>& nums) {
        
        vector<int> tmp(nums.size());
        return mergeSort(nums, tmp, 0, nums.size() - 1);
    }
    
private:
    long long mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        
        if (l >= r) return 0;
        
        int mid = l + (r - l) / 2;
        return mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r) +
            merge(nums, tmp, l, mid, r);
    }
    
    long long merge(vector<int>& nums, vector<int>& tmp, int l, int mid, int r) {
        
        long long res = 0;
        int i = l, j = mid + 1;
        int k = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                res += nums[i] * (r - j + 1);
                tmp[k++] = nums[i++];
            }
            else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        
        move(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        
        return res;
    }
};