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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;

        stack<pair<bool, TreeNode*>> s; // (print,node)：打印节点
        if (root) s.emplace(false, root);
        while (!s.empty()) {
            auto [print, node] = s.top();
            s.pop();
            if (print) {
                res.emplace_back(node->val);
            }
            else {
                if (node->right) s.emplace(false, node->right);
                s.emplace(true, node);
                if (node->left) s.emplace(false, node->left);
            }
        }
        return res;
    }
};