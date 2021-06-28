#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(k*C(n,k))
// Space complexity: O(k)

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        if (n <= 0 || k <= 0 || k > n)
            return {};

        ans.clear();

        vector<int> c;
        generateCombine(n, k, 1, c);

        return ans;
    }

private:
    vector<vector<int>> ans;

    void generateCombine(int n, int k, int start, vector<int> &c) {

        if (c.size() == k) {
            ans.push_back(c);
            return;
        }

        int max = n + 1 - k + c.size();
        for (int i = start; i <= max; i++) {
            c.push_back(i);
            generateCombine(n, k, i + 1, c);
            c.pop_back();
        }
    }
};

int main() {

    vector<vector<int>> ans = Solution().combine(4, 2);
    for (auto &c : ans) {
        for (auto &x : c)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}