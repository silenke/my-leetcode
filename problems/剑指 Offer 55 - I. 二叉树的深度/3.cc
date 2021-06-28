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
    int maxDepth(TreeNode* root) {

        queue<TreeNode*> q;
        if (root) q.push(root);
        int res = 0;
        while (!q.empty()) {
            res++;
            int n = q.size();
            while (n--) {
                root = q.front(); q.pop();
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        return res;
    }
};