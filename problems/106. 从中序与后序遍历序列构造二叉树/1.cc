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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        const int n = inorder.size();
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            map[inorder[i]] = i;
        }
        function<TreeNode*(int, int, int)> dfs = [&](int il, int pl, int n) {
            if (n == 0) return (TreeNode*)nullptr;
            int val = postorder[pl + n - 1];
            TreeNode* root = new TreeNode(val);
            int k = map[val];
            int l = k - il;
            root->left = dfs(il, pl, l);
            root->right = dfs(k + 1, pl + l, n - 1 - l);
            return root;
        };
        return dfs(0, 0, n);
    }
};