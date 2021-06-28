#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        int l = 0, r = arr.size() - 1;
        while (l < r) {
            swap(arr[l], arr[l + rand() % (r  -l + 1)]);
            int a = l, b = r + 1;
            int i = l;
            while (i < b) {
                if (arr[i] < arr[l]) swap(arr[++a], arr[i++]);
                else if (arr[i] == arr[l]) i++;
                else swap(arr[i], arr[--b]);
            }
            swap(arr[l], arr[a]);
            if (k < a) r = a - 1;   // 左边>k个
            else if (k > b) l = b;  // 左边<k个
            else break;
        }
        vector<int> res;
        res.insert(res.begin(), arr.begin(), arr.begin() + k);
        return res;
    }
};