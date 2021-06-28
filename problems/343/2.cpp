#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n^2)
// Space complexity: O(n)

class Solution {
public:
    int integerBreak(int n) {

        dp = vector<int>(n + 1, 0);
        return integerBreakH(n);
    }

private:
    vector<int> dp;

    int integerBreakH(int n) {

        if (n == 1)
            return 1;

        if (dp[n])
            return dp[n];

        int ans = 0;
        for (int i = 1; i < n; i ++)
            ans = max3(ans, i * (n - i), i * integerBreakH(n - i));
        return dp[n] = ans;
    }

    int max3(int a, int b, int c) {

        return max(a, max(b, c));
    }
};

int main() {

    cout << Solution().integerBreak(10) << endl;

    return 0;
}