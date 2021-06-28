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
    int countNodes(TreeNode* root) {

        return dfs(root, height(root));
    }

private:
    int height(TreeNode* root) {

        int h = 0;
        while (root) {
            h++;
            root = root->left;
        }
        return h;
    }

    int dfs(TreeNode* root, int h) {

        if (!root) return 0;

        if (height(root->right) == h - 1) {
            return (1 << (h - 1)) + dfs(root->right, h - 1);
        }
        return dfs(root->left, h - 1) + (1 << (h - 2));
    }
};