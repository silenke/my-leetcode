#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int l = lower(nums, target);
        if (l == nums.size() || nums[l] != target) return {-1, -1};
        int r = upper(nums, target);
        return {l, r - 1};
    }

private:
    int lower(vector<int>& nums, int target) {

        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int upper(vector<int>& nums, int target) {

        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};