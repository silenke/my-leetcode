#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Time complexity: O(n^n)
// Space complexity: O(n)

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        if (nums.empty())
            return {};

        ans.clear();

        vector<int> p;
        generatePermute(nums, 0, p);

        return ans;
    }

private:
    vector<vector<int>> ans;
    unordered_map<int, bool> used;

    void generatePermute(const vector<int> &nums, int index, vector<int> &p) {

        if (index == nums.size()) {
            ans.push_back(p);
            return;
        }

        for (const int &x : nums) {
            if (!used[x]) {
                p.push_back(x);
                used[x] = true;
                generatePermute(nums, index + 1, p);
                p.pop_back();
                used[x] = false;
            }
        }
    }
};

int main() {

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = Solution().permute(nums);
    for (auto &p : ans) {
        for (auto &x : p)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}