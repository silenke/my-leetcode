#include "..\..\leetcode.h"

class Solution {
public:
    string minNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end(), [&](int a, int b){
            return sum(a, b) < sum(b, a);
        });
        
        string res;
        for (int n : nums) {
            res += to_string(n);
        }
        return res;
    }

private:
    long long sum(long long a, int b) {

        int c = b;
        do {
            a *= 10;
            c /= 10;
        } while (c);
        return a + b;
    }
};