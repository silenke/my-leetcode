#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp(n + 1);

        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

int main() {

    cout << Solution().climbStairs(3) << endl;

    return 0;
}