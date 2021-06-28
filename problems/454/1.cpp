#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Time complexity: O(n^2)
// Space complexity: O(n^2)

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

        unordered_map<int, int> map;
        for (int &a : A)
            for (int &b : B)
                map[a + b]++;

        int ans = 0;
        for (int &c : C)
            for (int &d : D)
                ans += map[0 - c - d];

        return ans;
    }
};

int main() {

    vector<int> A = {1, 2}, B = {-2, -1}, C = {-1, 2}, D = {0, 2};
    int ans = Solution().fourSumCount(A, B, C, D);
    cout << ans << endl;

    return 0;
}