#include "..\..\leetcode.h"

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        int max_stone = *max_element(stones.begin(), stones.end());
        vector<int> counts(max_stone + 1, 0);
        for (int s : stones) counts[s]++;
        int i = max_stone;  // 最大重量
        int j = max_stone - 1;  // 次大重量
        while (j > 0 && counts[j] == 0) j--;
        while (i > 0) {
            if ((counts[i] & 1) == 0) {
                i = j;
                while (i > 0 && counts[i] == 0) i--;
                j = i - 1;
                while (j > 0 && counts[j] == 0) j--;
            }
            else {
                if (j <= 0) break;
                int k = i - j;
                counts[k]++;
                counts[j]--;
                if (k > j) {
                    i = k;
                    while (j > 0 && counts[j] == 0) j--;
                }
                else {
                    i = j;
                    while (i > 0 && counts[i] == 0) i--;
                    j = i - 1;
                    while (j > 0 && counts[j] == 0) j--;
                }
            }
        }
        return i;
    }
};