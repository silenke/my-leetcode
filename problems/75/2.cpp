#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {

        // [0,zero] are 0, (zero,i) are 1, [two, n) are 2
        int zero = -1;
        int two = nums.size();
        int i = 0;
        while (i < two) {
            if (nums[i] == 1)
                i++;
            else if (nums[i] == 2)
                swap(nums[i], nums[--two]);
            else {
                assert(nums[i] == 0);
                swap(nums[++zero], nums[i++]);
            }
        }
    }
};

int main() {

    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution().sortColors(nums);
    for (auto &x : nums)
        cout << x << " ";
    cout << endl;
    return 0;
}