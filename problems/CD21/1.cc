#include "bits/stdc++.h"

using namespace std;

class Solution { 
public:
    typedef long long ll; 
    
    ll mergeSort(vector<int>& nums) {
        
        return mergeSort(nums, 0, nums.size() - 1);
    }
    
private:
    ll mergeSort(vector<int>& nums, int l, int r) {
        
        if (l >= r) return 0;
        
        int mid = l + (r - l) / 2;
        return mergeSort(nums, l, mid) +
            mergeSort(nums, mid + 1, r) +
            merge(nums, l, mid, r);
    }
    
    ll merge(vector<int>& nums, int l, int mid, int r) {
        
        ll res = 0;
        
        vector<int> tmp(r - l + 1);
        int i = l, j = mid + 1;
        int k = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                res += nums[i] * (r - j + 1);
                tmp[k++] = nums[i++];
            }
            else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        
        move(tmp.begin(), tmp.end(), nums.begin() + l);
        
        return res;
    }
};

int main() {
    
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << Solution().mergeSort(nums);
    
    return 0;
}