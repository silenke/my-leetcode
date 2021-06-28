#include "..\..\leetcode.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {

        const int n = T.size();
        vector<int> res(n, 0);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while(!s.empty() && T[s.top()] < T[i]) {
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};