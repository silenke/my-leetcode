#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    bool hasPathSum(TreeNode* root, int sum) {
        
        queue<pair<TreeNode*, int>> q;
        if (root) q.emplace(root, sum);
        while (!q.empty()) {
            auto [node, num] = q.front();
            q.pop();
            if (!node->left && !node->right) {
                if (node->val == num) return true;
                continue;
            }
            if (node->left) q.emplace(node->left, num - node->val);
            if (node->right) q.emplace(node->right, num - node->val);
        }
        return false;
    }
};