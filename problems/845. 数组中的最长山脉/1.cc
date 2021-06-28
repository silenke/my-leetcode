#include "..\..\leetcode.h"

class Solution {
public:
    int longestMountain(vector<int>& arr) {

        const int n = arr.size();
        int res = 0;
        int l = 0;
        while (l < n - 2) {
            int r = l + 1;
            if (arr[l] < arr[l + 1]) {
                while (r + 1 < n - 1 && arr[r] < arr[r + 1]) r++;
                if (r < n - 1 && arr[r] > arr[r + 1]) {
                    while (r + 1 < n && arr[r] > arr[r + 1]) r++;
                    res = max(res, r - l + 1);
                }
                else {
                    r++;
                }
            }
            l = r;
        }
        return res;
    }
};