#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

        unordered_map<int, int> map;    // a+b，出现的次数
        for (int a : A) {
            for (int b : B) {
                map[a + b]++;
            }
        }

        int res = 0;
        for (int c : C) {
            for (int d : D) {
                auto it = map.find(0 - c - d);
                if (it != map.end()) {
                    res += it->second;
                }
            }
        }
        return res;
    }
};