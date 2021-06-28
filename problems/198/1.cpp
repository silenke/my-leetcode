#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(2^n)
// Space complexity: O(n)

class Solution {
public:
    int rob(vector<int>& nums) {

        return robHelp(nums, 0);
    }

private:
    int robHelp(vector<int> &nums, int n) {

        if (n >= nums.size())
            return 0;

        int ans = -1;
        for (int i = n; i < nums.size(); i++)
            ans = max(ans, nums[i] + robHelp(nums, i + 2));
        return ans;
    }
};

int main() {

    vector<int> nums{2, 7, 9, 3, 1};
    cout << Solution().rob(nums) << endl;

    return 0;
}