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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> ppath;
        vector<TreeNode*> qpath;
        vector<TreeNode*> path;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root || !ppath.empty() && !qpath.empty()) return;
            path.emplace_back(root);
            if (root == p) ppath = path;
            else if (root == q) qpath = path;
            dfs(root->left);
            dfs(root->right);
            path.pop_back();
        };
        dfs(root);
        int i = 0;
        while (i < ppath.size() && i < qpath.size() && ppath[i] == qpath[i]) i++;
        return ppath[i - 1];
    }
};