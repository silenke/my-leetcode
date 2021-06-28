#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n^2)
// Space complexity: O(n)

class Solution {
public:
    int rob(vector<int>& nums) {

        dp = vector<int>(nums.size(), -1);
        return robHelp(nums, 0);
    }

private:
    vector<int> dp;

    int robHelp(vector<int> &nums, int n) {

        if (n >= nums.size())
            return 0;

        if (dp[n] >= 0)
            return dp[n];

        int ans = -1;
        for (int i = n; i < nums.size(); i++)
            ans = max(ans, nums[i] + robHelp(nums, i + 2));
        return dp[n] = ans;
    }
};

int main() {

    vector<int> nums{2, 7, 9, 3, 1};
    cout << Solution().rob(nums) << endl;

    return 0;
}