#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        const int n = pages.size();
        int max_p = 0;
        int sum = 0;
        for (int p : pages) {
            max_p = max(max_p, p);
            sum += p;
        }

        int l = max_p, r = sum;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (count(pages, m) <= k) r = m;
            else l = m + 1;
        }
        return l;
    }

private:
    int count(const vector<int>& pages, int time) {

        int res = 1;
        int sum = 0;
        for (int p : pages) {
            if (sum + p > time) {
                res++;
                sum = 0;
            }
            sum += p;
        }
        return res;
    }
};