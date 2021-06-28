#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int r = 0;  // [0, r)：非零元素
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[r++], nums[i]);
            }
        }
    }
};