#include "..\..\leetcode.h"

class Solution {
public:
    string decodeString(string s) {

        int n = 0;
        string res;
        stack<int> nums;
        stack<string> strs;
        for (char c : s) {
            if (isdigit(c)) {
                n = n * 10 + (c - '0');
            }
            else if (isalpha(c)) {
                res += c;
            }
            else if (c == '[') {
                nums.push(n);
                n = 0;
                strs.push(res);
                res = "";
            }
            else {
                while (nums.top()--) {
                    strs.top() += res;
                }
                res = strs.top();
                nums.pop();
                strs.pop();
            }
        }
        return res;
    }
};