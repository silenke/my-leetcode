#include "..\..\leetcode.h"

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> sums(n);    // sums[i]：以位置i开始的最小和
        vector<int> rights(n);    // rights[i]：以位置i开始的最小和的右边界
        sums[n - 1] = nums[n - 1];
        rights[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (sums[i + 1] <= 0) {
                sums[i] = nums[i] + sums[i + 1];
                rights[i] = rights[i + 1];
            }
            else {
                sums[i] = nums[i];
                rights[i] = i;
            }
        }

        int res = 0;
        int sum = 0;
        int r = 0;
        for (int i = 0; i < n && r < n; i++) {
            while (r < n && sum + sums[r] <= k) {
                sum += sums[r];
                r = rights[r] + 1;
            }
            res = max(res, r - i);
            if (r > i) sum -= nums[i];
            else r = i + 1;
        }
        return res;
    }
};

int main() {
    
    int n, k;
    cin >> n >> k;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << Solution().maxLength(nums, k);
    
    return 0;
}