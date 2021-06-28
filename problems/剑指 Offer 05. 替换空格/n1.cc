#include "..\..\leetcode.h"

class Solution {
public:
    string replaceSpace(string s) {

        int count = std::count(s.begin(), s.end(), ' ');
        
        int n = s.size();
        int m = n + count * 2;
        s.resize(m);
        for (int i = n - 1, j = m - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                s[j--] = s[i];
            }
            else {
                j -= 2;
                s.replace(j--, 3, "%20");
            }
        }
        return s;
    }
};