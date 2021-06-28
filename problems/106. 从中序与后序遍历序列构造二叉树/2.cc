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

        if (inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(postorder.back());
        stack<TreeNode*> s;
        s.push(root);
        int j = inorder.size() - 1;
        for (int i = postorder.size() - 2; i >= 0; i--) {
            TreeNode* node = s.top();
            if (node->val != inorder[j]) {
                node->right = new TreeNode(postorder[i]);
                s.push(node->right);
            }
            else {
                while (!s.empty() && s.top()->val == inorder[j]) {
                    node = s.top(); s.pop();
                    j--;
                }
                node->left = new TreeNode(postorder[i]);
                s.push(node->left);
            }
        }
        return root;
    }
};