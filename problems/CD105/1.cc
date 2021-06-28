#include "..\..\leetcode.h"

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int couples(vector<int>& heights) {

        int n = heights.size();

        if (n <= 2) return n - 1;

        int maxIndex = 0;   // 第一个最大元素的索引
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] > heights[maxIndex]) {
                maxIndex = i;
            }
        }

        int res = 0;
        stack<int> s;
        s.emplace(heights[maxIndex]);
        int i = next(maxIndex, n);
        while (i != maxIndex) {
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
            i = next(i, n);
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

private:
    int next(int i, int n) {

        return i + 1 < n ? i + 1 : 0;
    }
};

int main() {
    
    int n;
    cin >> n;
    
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    cout << Solution().couples(heights);
    
    return 0;
}