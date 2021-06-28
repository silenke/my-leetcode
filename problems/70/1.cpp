#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(2^n)
// Space complexity: O(n)

class Solution {
public:
    int climbStairs(int n) {
        
        if (n == 0 || n == 1)
            return 1;

        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main() {

    cout << Solution().climbStairs(3) << endl;

    return 0;
}