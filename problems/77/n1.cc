#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> c(k);
        dfs(n, k, 1, c, 0);
        return res;
    }

private:
    vector<vector<int>> res;

    void dfs(int n, int k, int i, vector<int>& c, int l)
    {   // i：可选择的最小元素，c：已经得到的结果，l：已经得到的长度
        if (l == k) {
            res.emplace_back(c);
            return;
        }

        int max = n + 1 - (k - l);   // [j,n] >= k-l，可用元素多于需要元素
        for (int j = i; j <= max; j++) {
            c[l] = j;
            dfs(n, k, j + 1, c, l + 1);
        }
    }
};