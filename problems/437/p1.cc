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
    int pathSum(TreeNode* root, int sum) {
        
        if (root == nullptr) return 0;
        return pathSumFromRoot(root, sum) + 
            pathSum(root->left, sum) + pathSum(root->right, sum);
    }

private:
    int pathSumFromRoot(TreeNode* root, int sum) {

        if (root == nullptr) return 0;

        sum -= root->val;
        return (sum == 0) + pathSumFromRoot(root->left, sum) + 
            pathSumFromRoot(root->right, sum);
    }
};