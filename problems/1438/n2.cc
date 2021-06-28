class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int res = 0;
        deque<int> maxs, mins;
        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
            
            while (!maxs.empty() && nums[maxs.back()] <= nums[i]) {
                maxs.pop_back();
            }
            maxs.emplace_back(i);

            while (!mins.empty() && nums[mins.back()] >= nums[i]) {
                mins.pop_back();
            }
            mins.emplace_back(i);

            while (l <= i && nums[maxs.front()] - nums[mins.front()] > limit) {
                if (maxs.front() < mins.front()) {
                    l = maxs.front() + 1;
                    maxs.pop_front();
                }
                else {
                    l = mins.front() + 1;
                    mins.pop_front();
                }
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};