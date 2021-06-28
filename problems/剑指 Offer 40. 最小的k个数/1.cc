#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        vector<int> res;
        partition(arr, k - 1, 0, arr.size() - 1, res);
        return res;
    }

private:
    void partition(vector<int>& arr, int k, int l, int r, vector<int>& res) {

        if (l >= r) {
            res.insert(res.begin(), arr.begin(), arr.begin() + k + 1);
            return;
        }

        swap(arr[l], arr[l + rand() % (r - l + 1)]);
        int a = l;
        int b = r + 1;
        int i = l + 1;
        while (i < b) {
            if (arr[i] < arr[l]) swap(arr[++a], arr[i++]);
            else if (arr[i] == arr[l]) i++;
            else swap(arr[i], arr[--b]);
        }
        swap(arr[l], arr[a--]);

        if (k <= a) return partition(arr, k, l, a, res);
        if (k >= b) return partition(arr, k, b, r, res);
        res.insert(res.begin(), arr.begin(), arr.begin() + k + 1);
    }
};