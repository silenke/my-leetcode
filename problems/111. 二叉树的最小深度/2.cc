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
    int minDepth(TreeNode* root) {
        
        int res = 0;
        queue<TreeNode*> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            res++;
            int n = q.size();
            while (n--) {
                root = q.front(); q.pop();
                if (!root->left && !root->right) return res;
                if (root->left) q.emplace(root->left);
                if (root->right) q.emplace(root->right); 
            }
        }
        return res;
    }
};