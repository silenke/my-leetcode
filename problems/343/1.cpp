#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(2^n)
// Space complexity: O(n)

class Solution {
public:
    int integerBreak(int n) {

        if (n == 1)
            return 1;

        int ans = 0;
        for (int i = 1; i < n; i++)
            ans = max3(ans, i * (n - i), i * integerBreak(n - i));
        return ans;
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