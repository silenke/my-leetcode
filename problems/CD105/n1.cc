#include "..\..\leetcode.h"

class Solution {
public:
    int couples(vector<int>& heights) {
        
        int n = heights.size();
        
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (heights[i] > heights[maxIndex]) {
                maxIndex = i;
            }
        }
        
        int res = 0;
        stack<int> s;
        s.emplace(heights[maxIndex]);
        for (int i = (maxIndex + 1) % n; i != maxIndex; i = (i + 1) % n) {
            int count = 0;
            while (s.top() < heights[i]) {
                int top = s.top(); s.pop();
                count++;
                if (top != s.top()) {
                    res += count * 2 + count * (count - 1) / 2;
                    count = 0;
                }
            }
            s.emplace(heights[i]);
        }
        
        int count = 0;
        while (!s.empty()) {
            int top = s.top(); s.pop();
            count++;
            if (s.empty() || top != s.top()) {
                res += count * min(2, static_cast<int>(s.size())) +
                    count * (count - 1) / 2;
                count = 0;
            }
        }
        return res;
    }
};