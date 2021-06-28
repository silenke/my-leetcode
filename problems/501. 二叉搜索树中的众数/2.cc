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
        int count = 0, max_count = 0;
        while (root) {
            TreeNode* left = root->left;
            if (left) {
                while (left->right && left->right != root) {
                    left = left->right;
                }
                if (!left->right) {
                    left->right = root;
                    root = root->left;
                    continue;
                }
                left->right = nullptr;
            }
            if (root->val == pre) count++;
            else {
                pre = root->val;
                count = 1;
            }
            if (count == max_count) res.emplace_back(pre);
            else if (count > max_count) {
                res.clear();
                res.emplace_back(pre);
                max_count = count;
            }
            root = root->right;
        }
        return res;
    }
};