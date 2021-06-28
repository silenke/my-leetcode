#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n^2)
// Space complexity: O(n)

class Solution {
public:
    int integerBreak(int n) {

        vector<int> dp(n + 1);

        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int max = 0;
            for (int j = 1; j < i; j++) {
                max = max3(max, j * (i - j), j * dp[i - j]);
            }
            dp[i] = max;
        }
        return dp[n];
    }

private:
    int max3(int a, int b, int c) {

        return max(a, max(b, c));
    }
};

int main() {

    cout << Solution().integerBreak(10) << endl;

    return 0;
}