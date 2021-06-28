#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> set1(nums1.begin(), nums1.end());

        unordered_set<int> ans;
        for (int &x : nums2)
            if (set1.find(x) != set1.end())
                ans.insert(x);

        return vector<int>(ans.begin(), ans.end());
    }
};

int main() {

    vector<int> nums1 = {1, 2, 2, 1}, nums2 = {2, 2};
    vector<int> ans = Solution().intersection(nums1, nums2);
    for (int &x : ans)
        cout << x << endl;

    return 0;
}