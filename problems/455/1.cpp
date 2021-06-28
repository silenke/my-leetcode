#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Time complexity: O(nlogn)
// Space complexity: O(1)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        int gi = 0, si = 0;
        int ans = 0;
        while (gi < g.size() && si < s.size()) {
            if (g[gi] <= s[si]) {
                ans++;
                gi++;
                si++;
            }
            else
                gi++;
        }

        return ans;
    }
};

int main() {

    vector<int> g{1,2,3}, s{1,1};
    cout << Solution().findContentChildren(g, s) << endl;

    return 0;
}