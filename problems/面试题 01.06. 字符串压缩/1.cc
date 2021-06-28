#include "..\..\leetcode.h"

class Solution {
public:
    string compressString(string S) {

        if (S.size() < 2) return S;

        string res;
        int n = 1;
        for (int i = 1; i < S.size(); i++) {
            if (S[i] == S[i - 1]) {
                n++;
            }
            else {
                res += S[i - 1] + to_string(n);
                n = 1;
            }
        }
        res += S.back() + to_string(n);
        return res.size() < S.size() ? res : S;
    }
};