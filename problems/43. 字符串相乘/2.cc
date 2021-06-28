#include "..\..\leetcode.h"

class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0") return "0";

        const int n1 = num1.size();
        const int n2 = num2.size();
        vector<int> num(n1 + n2);
        for (int i = 0; i < n1; i++) {
            int a = num1[i] - '0';
            for (int j = 0; j < n2; j++) {
                num[i + j + 1] += a * (num2[j] - '0');
            }
        }

        for (int i = num.size() - 1; i > 0; i--) {
            num[i - 1] += num[i] / 10;
            num[i] %= 10;
        }

        string res;
        for (int i = num[0] ? 0 : 1; i < num.size(); i++) {
            res.push_back(num[i] + '0');
        }
        return res;
    }
};