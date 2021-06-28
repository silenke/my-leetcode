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
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> res;
        postorderTraversal(root, res);
        return res;
    }

private:
    void postorderTraversal(TreeNode* root, vector<int>& res) {
        
        if (root) {
            postorderTraversal(root->left, res);
            postorderTraversal(root->right, res);
            res.emplace_back(root->val);
        }
    }
};