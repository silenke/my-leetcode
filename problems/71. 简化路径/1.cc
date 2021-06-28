#include "..\..\leetcode.h"

class Solution {
public:
    string simplifyPath(string path) {

        vector<string> stk;
        istringstream i(path);
        string j;
        while (getline(i, j, '/')) {
            if (j == "" || j == ".") continue;
            if (j != "..") stk.emplace_back(j);
            else if (!stk.empty()) stk.pop_back();
        }
        if (stk.empty()) return "/";
        string res;
        for (string& s : stk) {
            res.append("/" + s);
        }
        return res;
    }
};