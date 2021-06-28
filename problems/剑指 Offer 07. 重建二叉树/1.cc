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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> map;    // map[val]：整数val在inorder中的位置
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        function<TreeNode*(int, int, int)> dfs = [&](int l1, int l2, int n) {
            if (n == 0) return (TreeNode*)nullptr;
            int val = preorder[l1++];
            TreeNode* root = new TreeNode(val);
            int m2 = map[val];
            int l = m2 - l2;
            root->left = dfs(l1, l2, l);
            root->right = dfs(l1 + l, m2 + 1, n - l - 1);
            return root;
        };
        return dfs(0, 0, preorder.size());
    }
};