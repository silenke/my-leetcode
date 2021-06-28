#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        
        map.clear();
        map[0] = 1;
        return dfs(root, sum, 0);
    }

private:
    unordered_map<int, int> map;    // 前缀和，出现次数

    int dfs(TreeNode* root, int sum, int pre) {
        
        if (root == nullptr) return 0;

        pre += root->val;
        int res = map[pre - sum];

        map[pre]++;
        res += dfs(root->left, sum, pre) + dfs(root->right, sum, pre);
        map[pre]--;
        return res;
    }
};