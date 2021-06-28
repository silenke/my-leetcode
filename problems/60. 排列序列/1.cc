#include "..\..\leetcode.h"

class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> f(n);   // f[i]：i!
        f[0] = 1;
        for (int i = 1; i < n; i++) {
            f[i] = f[i - 1] * i;
        }

        string res;
        vector<bool> used(n);
        k--;
        for (int i = n - 1; i >= 0; i--) {
            int index = k / f[i];   // 落在哪个区间：0≤index<n
            for (int j = 0; j < n; j++) {
                if (used[j]) continue;
                if (index-- <= 0) {
                    res.push_back(j + 1 + '0');
                    used[j] = true;
                    break;
                }
            }
            k %= f[i];
        }
        return res;
    }
};