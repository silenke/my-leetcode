#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Time complexity: O(nlogk)
// Space complexity: O(k)

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        if (nums.size() < 2 || k < 1 || t < 0)
            return false;

        set<long long> s;
        for (int i = 0; i < nums.size(); i++) {
            auto it = s.lower_bound((long long)nums[i] - t);
            if (it != s.end() && *it <= (long long)nums[i] + t)
                return true;

            if (s.size() == k)
                s.erase(nums[i - k]);
            s.insert(nums[i]);
        }

        return false;
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 1};
    bool ans = Solution().containsNearbyAlmostDuplicate(nums, 3, 0);
    cout << ans << endl;

    return 0;
}