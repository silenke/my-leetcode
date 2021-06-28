#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n^c)
// Space complexity: O(c)

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for (int &x : nums)
            sum += x;

        if (sum % 2)
            return false;

        int c = sum / 2;
        vector<bool> dp(c + 1, false);
        for (int i = 0; i <= c; i++)
            dp[i] = (i == nums[0]);
        for (int i = 1; i < nums.size(); i++)
            for (int j = c; j >= nums[i]; j--)
                dp[j] = dp[j] || dp[j - nums[i]];

        return dp[c];
    }
};

int main() {

    vector<int> nums{1, 5, 11, 5};
    cout << Solution().canPartition(nums) << endl;

    return 0;
}