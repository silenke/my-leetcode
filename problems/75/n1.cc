#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int l = -1; // [0,l]：红色
        int r = nums.size(); // [r,n)：蓝色
        int i = 0;
        while (i < r) {
            if (nums[i] == 0) {
                swap(nums[++l], nums[i++]);
            }
            else if (nums[i] == 1) {
                i++;
            }
            else {
                swap(nums[--r], nums[i]);
            }
        }
    }
};