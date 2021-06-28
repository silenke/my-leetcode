#include "..\..\leetcode.h"

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
        
        unordered_map<int, int> map;    // map[pre]：前缀和pre出现的次数
        map[0] = 1;
        return dfs(root, sum, 0, map);
    }

private:
    int dfs(TreeNode* root, int sum, int pre, unordered_map<int, int>& map) {

        if (root == nullptr) return 0;

        pre += root->val;
        int res = map[pre - sum];

        map[pre]++;
        res += dfs(root->left, sum, pre, map) + dfs(root->right, sum, pre, map);
        map[pre]--;

        return res;
    }
};