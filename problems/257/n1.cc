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
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        if (!root) return {};

        string val = to_string(root->val);
        if (!root->left && !root->right) return  { val };

        vector<string> res;
        vector<string> leftPaths = binaryTreePaths(root->left);
        for (auto& path : leftPaths)
            res.emplace_back(val + "->" + path);
        vector<string> rightPaths = binaryTreePaths(root->right);
        for (auto& path : rightPaths)
            res.emplace_back(val + "->" + path);
        return res;
    }
};