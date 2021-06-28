#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        unordered_map<char, char> map {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        stack<char> stk;
        for (char c : s) {
            auto it = map.find(c);
            if (it != map.end())
                stk.emplace(it->second);
            else if (stk.empty() || stk.top() != c)
                return false;
            else
                stk.pop();
        }
        return stk.empty();
    }
};