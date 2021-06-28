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

        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> s;
        s.emplace(root);
        for (int i = 1, j = 0; i < preorder.size(); i++) {
            TreeNode* node = s.top();
            if (node->val != inorder[j]) {
                node->left = new TreeNode(preorder[i]);
                s.emplace(node->left);
            }
            else {
                while (!s.empty() && s.top()->val == inorder[j]) {
                    node = s.top(); s.pop();
                    j++;
                }
                node->right = new TreeNode(preorder[i]);
                s.emplace(node->right);
            }
        }
        return root;
    }
};