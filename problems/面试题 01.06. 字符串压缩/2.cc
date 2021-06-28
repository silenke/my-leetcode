#include "..\..\leetcode.h"

class Solution {
public:
    string compressString(string S) {

        if (S.size() < 2) return S;

        const int n = S.size();
        string res;
        int i = 0, j = 1;
        while (i < n) {
            while (j < n && S[j] == S[i]) j++;
            res += S[i] + to_string(j - i);
            i = j++;
        }
        return res.size() < S.size() ? res : S;
    }
};