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
    TreeNode* balanceBST(TreeNode* root) {

        vector<int> nums;
        function<void(TreeNode*)> inorder = [&](TreeNode* root) {
            if (!root) return;
            inorder(root->left);
            nums.push_back(root->val);
            inorder(root->right);
        };

        function<TreeNode*(int, int)> build = [&](int l, int r) {
            if (l > r) return (TreeNode*)nullptr;
            int mid = l + (r - l) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = build(l, mid - 1);
            root->right = build(mid + 1, r);
            return root;
        };

        inorder(root);
        return build(0, nums.size() - 1);
    }
};