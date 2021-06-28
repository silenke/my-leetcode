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

        TreeNode* curr;
        while (curr) {
            TreeNode* left = curr->left;
            if (left) {
                while (left->right && left->right != curr) {
                    left = left->right;
                }
                if (!left->right) {
                    left->right = curr;
                    curr = curr->left;
                }
                else {
                    left->right = nullptr;
                    print(curr->left, res);
                    curr = curr->right;
                }
            }
            else {
                curr = curr->right;
            }
        }
        print(root, res);
        return res;
    }

private:
    void print(TreeNode* root, vector<int>& res) {

        TreeNode* tail = reverse(root);
        TreeNode* curr = tail;
        while (curr) {
            res.emplace_back(curr->val);
            curr = curr->right;
        }
        reverse(tail);
    }

    TreeNode* reverse(TreeNode* root) {

        TreeNode* prev = nullptr;
        TreeNode* curr = root;
        while (curr) {
            TreeNode* right = curr->right;
            curr->right = prev;
            prev = curr;
            curr = right;
        }
        return prev;
    }
};