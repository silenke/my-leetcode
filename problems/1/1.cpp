#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end())
                return {map[complement], i};
            else
                map[nums[i]] = i;
        }

        return {};
    }
};

int main() {

    vector<int> nums = {2, 7, 11, 15};
    vector<int> ans = Solution().twoSum(nums, 9);
    for (int x : ans)
        cout << x << " ";

    return 0;
}