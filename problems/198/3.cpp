#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(2^n)
// Space complexity: O(n)

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n + 2, -1);

        dp[n] = dp[n + 1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int m = -1;
            for (int j = i; j < n; j++)
                m = max(m, nums[j] + dp[j + 2]);
            dp[i] = m;
        }
        return dp[0];
    }
};

int main() {

    vector<int> nums{2, 7, 9, 3, 1};
    cout << Solution().rob(nums) << endl;

    return 0;
}