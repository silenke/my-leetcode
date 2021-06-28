#include "..\..\leetcode.h"

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {

        const int n = arr.size();
        if (n < 3) return false;
        int i = 0;
        while (i < n - 2 && arr[i] < arr[i + 1]) i++;
        int j = n - 1;
        while (j > 1 && arr[j - 1] > arr[j]) j--;
        return i == j;
    }
};