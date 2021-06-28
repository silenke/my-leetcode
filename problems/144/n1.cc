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
        preorderTraversal(root, res);
        return res;
    }

private:
    void preorderTraversal(TreeNode* root, vector<int>& res) {

        if (root) {
            res.emplace_back(root->val);
            preorderTraversal(root->left, res);
            preorderTraversal(root->right, res);
        }
    }
};