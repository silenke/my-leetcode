#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // [0,k) are nonZeros, [k,i) are zreos, k -> first zero
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i])
                swap(nums[k++], nums[i]);
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