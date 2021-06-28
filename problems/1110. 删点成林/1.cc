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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        unordered_set<int> set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        root = dfs(root, set, res);
        if (root) res.push_back(root);
        return res;
    }

private:
    TreeNode* dfs(TreeNode* root, unordered_set<int>& set, vector<TreeNode*>& res) {
        
        if (root == nullptr) return nullptr;

        root->left = dfs(root->left, set, res);
        root->right = dfs(root->right, set, res);

        if (set.find(root->val) == set.end()) return root;

        if (root->left) res.push_back(root->left);
        if (root->right) res.push_back(root->right);
        // delete root;
        return nullptr;
    }
};