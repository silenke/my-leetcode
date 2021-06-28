#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        vector<int> dp(m + 1);
        // dp[j]：前i个物品可以装满容量j的背包
        // dp[i][j] = max{ dp[i-1][j], dp[i-1][j-a] + a }
        for (int a : A) {
            for (int j = m; j >= a; j--) {
                dp[j] = max(dp[j], dp[j - a] + a);
            }
        }
        return dp[m];
    }
};

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        vector<P> intervals{{0, 0}};
        for (int a : A) {
            vector<P> newIntervals;
            for (const auto& i : intervals) {
                newIntervals.emplace_back(i.first + a, i.second + a);
            }
            intervals = merge(intervals, newIntervals);
        }
        for (auto it = intervals.rbegin(); it != intervals.rend(); it++) {
            if (m > (*it).second) return (*it).second;
            if (m >= (*it).first) return m;
        }
        return 0;
    }

private:
    typedef pair<int, int> P;
    
    vector<P> merge(const vector<P>& a, const vector<P>& b) {
        
        vector<P> res;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i].first < b[j].first) insert(res, a[i++]);
            else insert(res, b[j++]);
        }
        while (i < a.size()) insert(res, a[i++]);
        while (j < b.size()) insert(res, b[j++]);
        return res;
    }

    void insert(vector<P>& res, const P& a) {
        
        if (res.empty() || res.back().second + 1 < a.first) res.emplace_back(a);
        res.back().second = max(res.back().second, a.second);
    }
};

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        vector<int> dp(m + 1);
        // dp[j]：前i个物品装进容量为j的背包的最大价值
        // dp[i][j] = max{ dp[i-1][j], dp[i-1][j-a] + v }
        for (int i = 0; i < A.size(); i++) {
            for (int j = m; j >= A[i]; j--) {
                dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
            }
        }
        return dp[m];
    }
};

class Solution {
public:
    /**
     * @param A: an integer array
     * @param V: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &A, vector<int> &V, int m) {
        // write your code here
        vector<int> dp(m + 1);
        // dp[j]：前i种物品装进容量为j的背包的最大价值
        // dp[i][j] = max{ dp[i-1][j], dp[i][j-a] + v }
        for (int i = 0; i < A.size(); i++) {
            for (int j = A[i]; j <= m; j++) {
                dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
            }
        }
        return dp[m];
    }
};

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        // write your code here
        vector<int> dp(target + 1);
        dp[0] = 1;
        // dp[j]：前i种物品装满容量为j的背包的方案数
        // dp[i][j] = dp[i-1][j] + dp[i-1][j-a]
        for (int n : nums) {
            for (int j = n; j <= target; j++) {
                dp[j] += dp[j - n];
            }
        }
        return dp[target];
    }
};

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        // write your code here
        vector<int> dp(target + 1);
        // dp[j]：前i个物品装满容量为j的背包的方法数
        // dp[i][j] = dp[i-1][j] + dp[i-1][j-a]
        dp[0] = 1;
        for (int n : nums) {
            for (int j = target; j >= n; j--) {
                dp[j] += dp[j - n];
            }
        }
        return dp[target];
    }
};

class Solution {
public:
    /**
     * @param n: the money of you
     * @param prices: the price of rice[i]
     * @param weight: the weight of rice[i]
     * @param amounts: the amount of rice[i]
     * @return: the maximum weight
     */
    int backPackVII(int n, vector<int> &prices, vector<int> &weight, vector<int> &amounts) {
        // write your code here
        vector<int> dp(n + 1);
        // dp[j]：前i个物品装进容量为j的背包的最大价值
        // dp[i][j] = max{ dp[i-1][j], dp[i-1][j-a] + v }
        for (int i = 0; i < prices.size(); i++) {
            while (amounts[i]--) {
                for (int j = n; j >= prices[i]; j--) {
                    dp[j] = max(dp[j], dp[j - prices[i]] + weight[i]);
                }
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    /**
     * @param n: the money of you
     * @param prices: the price of rice[i]
     * @param weight: the weight of rice[i]
     * @param amounts: the amount of rice[i]
     * @return: the maximum weight
     */
    int backPackVII(int n, vector<int> &prices, vector<int> &weight, vector<int> &amounts) {
        // write your code here
        vector<int> dp(n + 1);
        // dp[j]：前i个物品装进容量为j的背包的最大价值
        // dp[i][j] = max{ dp[i-1][j], dp[i-1][j-a] + v }
        for (int i = 0; i < prices.size(); i++) {
            int base = 1;
            while (amounts[i]) {
                int count = min(amounts[i], base);
                int p = prices[i] * count;
                int w = weight[i] * count;
                for (int j = n; j >= p; j--) {
                    dp[j] = max(dp[j], dp[j - p] + w);
                }
                base *= 2;
                amounts[i] -= count;
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    /**
     * @param n: the value from 1 - n
     * @param value: the value of coins
     * @param amount: the number of coins
     * @return: how many different value
     */
    int backPackVIII(int n, vector<int> &value, vector<int> &amount) {
        // write your code here
        vector<bool> dp(n + 1);
        // dp[j]：前i个物品可以装满容量为j的背包
        // dp[i][j] = dp[i-1][j] or dp[i][j-a]
        dp[0] = true;
        int res = 0;
        for (int i = 0; i < value.size(); i++) {
            vector<int> count(n + 1);
            for (int j = value[i]; j <= n; j++) {
                if (!dp[j] && dp[j - value[i]] && count[j - value[i]] < amount[i]) {
                    dp[j] = true;
                    count[j] = count[j - value[i]] + 1;
                    res++;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    /**
     * @param n: Your money
     * @param prices: Cost of each university application
     * @param probability: Probability of getting the University's offer
     * @return: the  highest probability
     */
    double backpackIX(int n, vector<int> &prices, vector<double> &probability) {
        // write your code here
        for (double& p : probability) {
            p = 1 - p;
        }
        vector<double> dp(n + 1, 1);
        // dp[j]：前i个学校使用j费用的全部失败的最小概率
        // dp[i][j = min{ dp[i-1][j], dp[i-1][j-w] * v }
        for (int i = 0; i < prices.size(); i++) {
            for (int j = n; j >= prices[i]; j--) {
                dp[j] = min(dp[j], dp[j - prices[i]] * probability[i]);
            }
        }
        return 1 - dp[n];
    }
};

class Solution {
public:
    /**
     * @param n: the money you have
     * @return: the minimum money you have to give
     */
    int backPackX(int n) {
        // write your code here
        vector<int> dp(n + 1);
        // dp[j]：前i种物品装进容量为j的背包获得的最大价值
        // dp[i][j] = max{ dp[i-1][j], dp[i][j-w] + w }
        for (int p : {150, 250, 350}) {
            for (int j = p; j <= n; j++) {
                dp[j] = max(dp[j], dp[j - p] + p);
            }
        }
        return n - dp[n];
    }
};
