#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kmp(const string& a, const string& b) {

        if (a.empty() || b.empty())
            return -1;

        next.clear();
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            }
            else if (next[j] == -1) {
                i++;
            }
            else {
                j = next[j];
            }
        }
        return j == b.size() ? i - j : -1;
    }

private:
    vector<int> next;
    void generate(const string& b) {
        
        next.reserve(b.size());
        if (next.size() == 1) {
            next[0] = 1;
            return;
        }

        next[0] = -1;
        next[1] = 0;
        int i = 2;
        int cn = 0;
        while (i < b.size()) {
            if (b[cn] == b[i - 1]) {
                next[i++] = ++cn;
            }
            else if (cn > 0) {
                cn = next[cn];
            }
            else {
                next[i++] = 0;
            }
        }
    }
};
