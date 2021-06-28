#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        // window is [l,r]
        int l = 0, r = -1;
        int sum = 0;
        int ret = nums.size() + 1;
        while (l < nums.size()) {
            if (r + 1 < nums.size() && sum < s)
                sum += nums[++r];
            else
                sum -= nums[l++];
            if (sum >= s)
                ret = min(ret, r - l + 1);
        }

        if (ret <= nums.size())
            return ret;
        else
            return 0;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int ret = Solution().minSubArrayLen(7, nums);
    cout << ret << endl;
    return 0;
}