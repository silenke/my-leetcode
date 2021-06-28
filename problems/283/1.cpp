#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        vector<int> nonZeroNums;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i])
                nonZeroNums.push_back(nums[i]);

        for (int i = 0; i < nonZeroNums.size(); i++)
            nums[i] = nonZeroNums[i];

        for (int i = nonZeroNums.size(); i < nums.size(); i++)
            nums[i] = 0;
    }
};

int main() {

    vector<int> nums = {0, 1, 0, 3, 12};
    Solution().moveZeroes(nums);
    for (auto &x : nums)
        cout << x << " ";
    cout << endl;
    return 0;
}