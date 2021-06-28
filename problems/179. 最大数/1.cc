#include "..\..\leetcode.h"

class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> strs(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            strs[i] = to_string(nums[i]);
        }
        sort(strs.begin(), strs.end(), [](string& a, string& b) {
            return a + b > b + a;
        });
        string res;
        for (const auto& s : strs) {
            res.append(s);
        }
        return res[0] == '0' ? "0" : res;
    }
};