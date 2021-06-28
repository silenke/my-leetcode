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
        
        TreeNode* curr = root;
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
                    printRightEdge(curr->left, res);
                    curr = curr->right;
                }
            }
            else {
                curr = curr->right;
            }
        }
        printRightEdge(root, res);
        return res;
    }

    void printRightEdge(TreeNode* root, vector<int>& res) {

        TreeNode* tail = reverse(root);
        TreeNode* curr = tail;
        while (curr) {
            res.emplace_back(curr->val);
            curr = curr->right;
        }
        reverse(tail);
    }

    TreeNode* reverse(TreeNode* root) {

        TreeNode* pre = nullptr;
        TreeNode* curr = root;
        while (curr) {
            TreeNode* next = curr->right;
            curr->right = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
};