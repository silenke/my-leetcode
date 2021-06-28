#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Time complexity: O(nlogn)
// Space complexity: O(nlogn)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        map<int, int> map1;
        for (int x : nums1)
            map1[x]++;

        vector<int> ans;
        for (int x : nums2)
            if (map1[x]) {
                ans.push_back(x);
                map1[x]--;
            }

        return ans;
    }
};

int main() {

    vector<int> nums1 = {1, 2, 2, 1}, nums2 = {2, 2};
    vector<int> ans = Solution().intersect(nums1, nums2);
    for (int &x : ans)
        cout << x << " ";

    return 0;
}