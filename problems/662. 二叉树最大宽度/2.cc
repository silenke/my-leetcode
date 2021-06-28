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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        if (root) {
            root->val = 0;
            q.push(root);
        }
        int res = 0;
        while (!q.empty()) {
            res = max(res, q.back()->val - q.front()->val + 1);
            int left = q.front()->val;
            int n = q.size();
            while (n--) {
                TreeNode* curr = q.front(); q.pop();
                if (curr->left) {
                    curr->left->val = (curr->val - left) * 2;
                    q.push(curr->left);
                }
                if (curr->right) {
                    curr->right->val = (curr->val - left) * 2 + 1;
                    q.push(curr->right);
                }
            }
        }
        return res;
    }
};