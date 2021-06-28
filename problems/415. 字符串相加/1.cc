#include "..\..\leetcode.h"

class Solution {
public:
    string addStrings(string num1, string num2) {

        const int n1 = num1.size();
        const int n2 = num2.size();

        vector<int> nums(max(n1, n2) + 1, 0);
        int k = nums.size() - 1;
        int i = n1 - 1, j = n2 - 1;
        int c = 0;
        while (i >= 0 || j >= 0 || c > 0) {
            if (i >= 0) c += num1[i--] - '0';
            if (j >= 0) c += num2[j--] - '0';
            nums[k--] = c % 10;
            c /= 10;
        }

        string res;
        k++;
        while (k < nums.size()) {
            res.push_back(nums[k++] + '0');
        }
        return res;
    }
};