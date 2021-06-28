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
    vector<int> findMode(TreeNode* root) {

        vector<int> res;
        int pre = INT_MIN;
        int count = 0, maxCount = 0;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) return;
            dfs(root->left);
            if (root->val == pre) count++;
            else {
                pre = root->val;
                count = 1;
            }
            if (count == maxCount) res.emplace_back(pre);
            else if (count > maxCount) {
                res.clear();
                res.emplace_back(pre);
                maxCount = count;
            }
            dfs(root->right);
        };
        dfs(root);
        return res;
    }
};