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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        vector<vector<int>> res;
        unordered_map<TreeNode*, TreeNode*> map;
        queue<pair<TreeNode*, int>> q;
        if (root) q.emplace(root, sum);
        while (!q.empty()) {
            tie(root, sum) = q.front(); q.pop();
            sum -= root->val;
            if (root->left) {
                map[root->left] = root;
                q.emplace(root->left, sum);
            }
            if (root->right) {
                map[root->right] = root;
                q.emplace(root->right, sum);
            }
            if (!root->left && !root->right && !sum) {
                vector<int> path;
                TreeNode* curr = root;
                while (root) {
                    path.emplace_back(root->val);
                    root = map[root];
                }
                reverse(path.begin(), path.end());
                res.emplace_back(move(path));
            }
        }
        return res;
    }
};