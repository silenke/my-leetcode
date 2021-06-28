#include "..\..\leetcode.h"

class Solution {
public:
    int findKthNumber(int n, int k) {

        long curr = 1;
        while (k > 1) {
            int count = getCount(n, curr);
            if (k > count) {
                k -= count;
                curr++;
            }
            else {
                k--;
                curr *= 10;
            }
        }
        return curr;
    }

private:
    int getCount(int n, long curr) {
        int count = 0;
        long next = curr + 1;
        while (curr <= n) {
            count += min(n - curr + 1, next - curr);
            curr *= 10;
            next *= 10;
        }
        return count;
    }
};