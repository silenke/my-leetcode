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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        stack<TreeNode*> s;
        for (int n : nums) {
            TreeNode* curr = new TreeNode(n);
            while (!s.empty() && s.top()->val < n) {
                TreeNode* top = s.top();
                s.pop();
                if (s.empty() || s.top()->val > n) {
                    curr->left = top;
                }
                else {
                    s.top()->right = top;
                }
            }
            s.emplace(curr);
        }

        while (s.size() > 1) {
            TreeNode* top = s.top();
            s.pop();
            s.top()->right = top;
        }
        return s.top();
    }
};