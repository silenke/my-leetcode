#include "..\..\leetcode.h"

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        const int n = arr.size();
        if (n < 3) return false;
        int i = 0;
        if (arr[i] < arr[i + 1]) {
            while (i + 1 < n - 1 && arr[i] < arr[i + 1]) i++;
            if (i < n - 1 && arr[i] > arr[i + 1]) {
                while (i + 1 < n && arr[i] > arr[i + 1]) i++;
                if (i + 1 == n) return true;
            }
        }
        return false;
    }
};