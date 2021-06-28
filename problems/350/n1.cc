#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> map;    // 元素：出现次数
        for (int n : nums1) {
            map[n]++;
        }

        vector<int> res;
        for (int n : nums2) {
            auto it = map.find(n);
            if (it != map.end()) {
                res.emplace_back(n);
                if (--it->second == 0) {
                    map.erase(it);
                }
            }
        }
        return res;
    }
};