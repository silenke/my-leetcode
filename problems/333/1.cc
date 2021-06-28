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
    int largestBSTSubtree(TreeNode* root) {

        return get<2>(dfs(root));
    }

private:
    tuple<int, int, int> dfs(TreeNode* root) {
        // 以 root 为根节点的树中最大 BST 的（最小值，最大值，节点数）
        
        if (root == nullptr) return {INT_MAX, INT_MIN, 0};

        auto [lmin, lmax, lnum] = dfs(root->left);
        auto [rmin, rmax, rnum] = dfs(root->right);

        if (lmax < root->val && root->val < rmin) {
            return {min(lmin, root->val), max(rmax, root->val), lnum + rnum + 1};
        }
        return {INT_MIN, INT_MAX, max(lnum, rnum)};
    }
};