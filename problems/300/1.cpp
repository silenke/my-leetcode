#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n^2)
// Space complexity: O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            int m = 1;
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                    m = max(m, 1 + dp[j]);
            dp[i] = m;
        }

        int ans = 0;
        for (int i = 0; i < dp.size(); i++)
            ans = max(ans, dp[i]);

        return ans;
    }
};

int main() {

    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    cout << Solution().lengthOfLIS(nums) << endl;

    return 0;
}