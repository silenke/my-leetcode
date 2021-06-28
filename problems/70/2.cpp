#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    int climbStairs(int n) {

        dp = vector<int>(n + 1, 0);
        return climbStarisHelper(n);
    }

private:
    vector<int> dp;

    int climbStarisHelper(int n) {

        if (n == 0 || n == 1)
            return 1;

        if (!dp[n])
            dp[n] = climbStarisHelper(n - 1) + climbStarisHelper(n - 2);
        return dp[n];
    }
};

int main() {

    cout << Solution().climbStairs(3) << endl;

    return 0;
}