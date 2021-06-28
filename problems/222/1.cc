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
    int countNodes(TreeNode* root) {

        return countNodes(root, 1, depth(root, 1));
    }

private:
    int countNodes(TreeNode* root, int d, int maxd) {
        
        if (root == nullptr) return 0;

        if (depth(root->right, d + 1) == maxd) {
            return (1 << (maxd - d - 1)) + countNodes(root->right, d + 1, maxd);
        }
        return (1 << (maxd - d - 2)) + countNodes(root->left, d + 1, maxd);
    }

    int depth(TreeNode* root, int d) {

        while (root) {
            d++;
            root = root->left;
        }
        return d;
    }
};