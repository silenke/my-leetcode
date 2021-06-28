#include "..\..\leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {

        unordered_map<int, int> map;
        for (int i = 0; i < post.size(); i++) {
            map[post[i]] = i;
        }
        function<TreeNode*(int, int, int)> dfs = [&](int i, int j, int n) {
            if (n <= 0) return (TreeNode*)nullptr;
            TreeNode* root = new TreeNode(pre[i++]);
            if (n == 1) return root;
            int k = map[pre[i]];
            int l = k - j + 1;
            root->left = dfs(i, j, l);
            root->right = dfs(i + l, k + 1, n - 1 - l);
            return root;
        };
        return dfs(0, 0, pre.size());
    }
};