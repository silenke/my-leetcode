#include "..\..\leetcode.h"

class Solution {
public:
    string minNumber(vector<int>& nums) {

        vector<string> strs(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            strs[i] = to_string(nums[i]);
        }

        sort(strs.begin(), strs.end(), [](string& a, string& b){ return a + b < b + a;} );

        string res;
        for (string& s : strs) {
            res += s;
        }
        return res;
    }
};