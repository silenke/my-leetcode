#include "..\..\leetcode.h"

class Solution {
public:
    string minString(vector<string> strs) {
        
        sort(strs.begin(), strs.end(), [](string& a, string& b){
            return a + b < b + a;
        });
        
        string res;
        for (auto& s : strs) {
            res += s;
        }
        return res;
    }
};