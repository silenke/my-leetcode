#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

// Time complexity: O(nlog(n-k))
// Space complexity: O(n-k)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> ans;

        unordered_map<int, int> map;
        for (int &x : nums)
            map[x]++;

        int n = map.size() - k;
        priority_queue<pair<int, int>> pq;
        for (auto &x : map) {
            pq.push(make_pair(x.second, x.first));
            if (pq.size() > n) {
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }

        return ans;
    }
};

int main() {

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> ans = Solution().topKFrequent(nums, 2);
    for (int &x : ans)
        cout << x << " ";

    return 0;
}