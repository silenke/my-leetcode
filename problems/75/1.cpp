#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int count[3] = {0};
        for (int i = 0; i < nums.size(); i++) {
            assert(nums[i] >= 0 && nums[i] < 3);
            count[nums[i]]++;
        }

        int index = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < count[i]; j++)
                nums[index++] = i;
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