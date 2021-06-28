#include "..\..\leetcode.h"

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> counts;
        for (char c : s) counts[c]++;

        unordered_map<int, string> bucket;
        int max_count = 0;
        for (auto [c, count] : counts) {
            bucket[count].push_back(c);
            max_count = max(max_count, count);
        }
        
        string res;
        for (int i = max_count; res.size() < s.size(); i--) {
            for (char c : bucket[i]) {
                res.append(i, c);
            }
        }
        return res;
    }
};