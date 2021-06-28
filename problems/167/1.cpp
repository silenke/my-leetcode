#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        if (numbers.size() < 2)
            return {};

        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target)
                return {l + 1, r + 1};
            else if (sum < target)
                l++;
            else
                r--;
        }

        return {};
    }
};

int main() {

    vector<int> nums = {2, 7, 11, 15};
    vector<int> ret = Solution().twoSum(nums, 9);
    for (auto &x : ret)
        cout << x << " ";
    cout << endl;
    return 0;
}