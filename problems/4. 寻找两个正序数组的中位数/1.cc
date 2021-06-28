#include "..\..\leetcode.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size()) nums1.swap(nums2);

        const int n1 = nums1.size();
        const int n2 = nums2.size();

        int n = n1 + (n2 - n1 + 1) / 2; // 左边的数量
        int i = 0, j = n1;  // 确保l的取值范围是[0,n1]
        while (i <= j) {
            int l = i + (j - i) / 2;    // 数组1左边的数量
            int r = n - l;  // 数组2左边的数量
            if (l > i && nums1[l - 1] > nums2[r]) j = l - 1;
            else if (l < n1 && nums1[l] < nums2[r - 1]) i = l + 1;
            else {
                int lmax = INT_MIN;
                if (l == 0) lmax = nums2[r - 1];
                else if (r == 0) lmax = nums1[l - 1];
                else lmax = max(nums1[l - 1], nums2[r - 1]);
                if ((n2 - n1) & 1) return lmax;

                int rmin = INT_MAX;
                if (l == n1) rmin = nums2[r];
                else if (r == n2) rmin = nums1[l];
                else rmin = min(nums1[l], nums2[r]);
                return (lmax + rmin) * 0.5;
            }
        }
        return -1;
    }
};