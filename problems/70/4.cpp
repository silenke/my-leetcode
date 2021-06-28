#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    int climbStairs(int n) {

        int dp0, dp1, dp2;

        dp0 = dp1 = dp2 = 1;
        for (int i = 2; i <= n; i++) {
            dp2 = dp0 + dp1;
            dp0 = dp1;
            dp1 = dp2;
        }
        return dp2;
    }
};

int main() {

    cout << Solution().climbStairs(3) << endl;

    return 0;
}