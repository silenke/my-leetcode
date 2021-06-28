#include "..\..\leetcode.h"

class Solution {
public:
    string replaceSpace(string s) {

        int count = 0;
        for (char c : s) {
            if (c == ' ') count++;
        }
        
        int n = s.size();
        int m = n + count * 2;
        s.resize(m);
        for (int i = n - 1, j = m - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            }
            else {
                s[j--] = s[i];
            }
        }
        return s;
    }
};