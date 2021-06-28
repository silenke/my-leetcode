#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int hashtable[256] = {0};
        // window is [l,r]
        int l = 0, r = -1;
        int ret = 0;
        while (l < s.size()) {
            if (r + 1 < s.size() && !hashtable[s[r + 1]])
                hashtable[s[++r]] = 1;
            else
                hashtable[s[l++]] = 0;
            ret = max(ret, r - l + 1);
        }

        return ret;
    }
};

int main() {

    string s = "abcabcbb";
    int ret = Solution().lengthOfLongestSubstring(s);
    cout << ret << endl;
    return 0;
}