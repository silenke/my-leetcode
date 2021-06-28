#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<int> res;
        for (int k1 = 0; k1 <= k; k1++) {
            int k2 = k - k1;
            if (k1 > nums1.size() || k2 > nums2.size()) continue;
            res = max(res, maxNumber(maxNumber(nums1, k1), maxNumber(nums2, k2)));
        }
        return res;
    }

private:
    vector<int> maxNumber(const vector<int>& nums, int k) {

        if (k == 0) return {};

        vector<int> res;
        int count = nums.size() - k;
        for (int n : nums) {
            while (!res.empty() && res.back() < n && count-- > 0) {
                res.pop_back();
            }
            res.emplace_back(n);
        }
        res.resize(k);
        return res;
    }

    vector<int> maxNumber(const vector<int>& nums1, const vector<int>& nums2) {

        vector<int> res;
        auto b1 = nums1.cbegin();
        auto e1 = nums1.cend();
        auto b2 = nums2.cbegin();
        auto e2 = nums2.cend();
        while (b1 != e1 || b2 != e2) {
            res.emplace_back(lexicographical_compare(b1, e1, b2, e2) ? *b2++: *b1++);
        }
        return res;
    }
};