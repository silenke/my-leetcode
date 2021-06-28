#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(k)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            if (set.find(nums[i]) != set.end())
                return true;

            set.insert(nums[i]);
            if (set.size() == k + 1)
                set.erase(nums[i - k]);
        }

        return false;
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 1};
    bool ans = Solution().containsNearbyDuplicate(nums, 3);
    cout << ans << endl;

    return 0;
}