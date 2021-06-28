#include <bits/stdc++.h>
using namespace std;

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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;

        stack<pair<bool, TreeNode*>> s; // 0：入栈，1：访问
        if (root) s.emplace(0, root);
        while (!s.empty()) {
            auto [b, node] = s.top();
            s.pop();
            if (b) {
                res.emplace_back(node->val);
            }
            else {
                if (node->right) s.emplace(0, node->right);
                if (node->left) s.emplace(0, node->left);
                s.emplace(1, node);
            }
        }
        return res;
    }
};