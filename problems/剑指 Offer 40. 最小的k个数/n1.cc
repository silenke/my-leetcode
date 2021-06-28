#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        function<void(int, int)> dfs = [&](int l, int r) {
            if (l >= r) return;
            swap(arr[l], arr[l + rand() % (r - l + 1)]);
            int a = l, b = r + 1;
            int i = l + 1;
            while (i < b) {
                if (arr[i] < arr[l]) swap(arr[++a], arr[i++]);
                else if (arr[i] == arr[l]) i++;
                else swap(arr[i], arr[--b]);
            }
            swap(arr[l], arr[a]);
            if (k <= a) dfs(l, a - 1);
            else if (k > b) dfs(b, r);
        };
        dfs(0, arr.size() - 1);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};