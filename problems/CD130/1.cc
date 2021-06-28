#include "..\..\leetcode.h"

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string minString(vector<string> strs) {
        
        sort(strs.begin(), strs.end(), [](const string& a, const string& b){
            return a + b < b + a;
        });
        string res;
        for (const string& s : strs) {
            res += s;
        }
        return res;
    }
};

int main() {
    
    int n;
    cin >> n;
    
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    
    cout << Solution().minString(strs);
    
    return 0;
}