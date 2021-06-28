#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kmp(const string& s1, const string& s2) {

        if (s1.empty() || s2.empty()) {
            return -1;
        }

        generate(s2);

        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            }
            else if (j > 0) {
                j = next[j];
            }
            else {
                i++;
            }
        }
        return j == s2.size() ? j - i : -1;
    }

private:
    vector<int> next;

    void generate(const string& s) {

        if (s.size() == 1) {
            return;
        }

        next.resize(s.size());
        next[0] = -1;
        next[1] = 0;
        int cn = 0;
        int i = 2;
        while (i < s.size()) {
            if (s[cn] == s[i - 1]) {
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