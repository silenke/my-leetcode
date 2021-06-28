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
    int kthLargest(TreeNode* root, int k) {

        stack<TreeNode*> s;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->right;
            }
            else {
                root = s.top(); s.pop();
                if (--k == 0) break;
                root = root->left;
            }
        }
        return root->val;
    }
};