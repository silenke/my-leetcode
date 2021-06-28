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

        function<TreeNode*(int, int, int)> dfs = [&](int l1, int l2, int n) {
            if (n <= 0) return (TreeNode*)(nullptr);
            TreeNode* root = new TreeNode(pre[l1++]);
            if (n == 1) return root;
            int m2 = l2;
            while (post[m2] != pre[l1]) m2++;
            int k = m2 - l2 + 1;
            root->left = dfs(l1, l2, k);
            root->right = dfs(l1 + k, m2 + 1, n - 1 - k);
            return root;
        };
        return dfs(0, 0, pre.size());
    }
};