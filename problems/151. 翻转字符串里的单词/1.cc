#include "..\..\leetcode.h"

class Solution {
public:
    string reverseWords(string s) {

        const int n = s.size();

        reverse(s, 0, n - 1);

        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && s[i] == ' ') i++;
            j = i;
            while (j < n && s[j] != ' ') j++;
            reverse(s, i, j - 1);
            i = j;
        }

        i = 0, j = 0;
        while (j < n) {
            while (j < n && s[j] == ' ') {
                j++;
            }
            if (j >= n) break;
            while (j < n && s[j] != ' ') {
                s[i++] = s[j++];
            }
            s[i++] = ' ';
        }
        return s.substr(0, i - 1);
    }

private:
    void reverse(string& s, int l, int r) {

        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }
};