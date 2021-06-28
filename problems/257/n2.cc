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

        res.clear();
        dfs(root, "");
        return res;
    }

private:
    vector<string> res;

    void dfs(TreeNode* root, string path) {
        
        if (!root) return;

        if (!root->left && !root->right) {
            res.emplace_back(path + to_string(root->val));
            return;
        }
        dfs(root->left, path + to_string(root->val) + "->");
        dfs(root->right, path + to_string(root->val) + "->");
    }
};