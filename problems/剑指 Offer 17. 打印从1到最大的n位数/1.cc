#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> printNumbers(int n) {
        
        vector<int> res(pow(10, n) - 1);
        iota(res.begin(), res.end(), 1);
        return res;
    }
};