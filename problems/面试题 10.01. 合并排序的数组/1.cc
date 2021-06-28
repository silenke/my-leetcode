#include "..\..\leetcode.h"

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {

        int i = A.size() - B.size() - 1;
        int j = B.size() - 1;
        int k = A.size() - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] > B[j]) A[k--] = A[i--];
            else A[k--] = B[j--];
        }
        while (j >= 0) {
            A[k--] = B[j--];
        }
    }
};