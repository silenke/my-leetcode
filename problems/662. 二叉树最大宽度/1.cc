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
    int widthOfBinaryTree(TreeNode* root) {
        
        vector<long long> ids;
        return dfs(root, 0, 0, ids);
    }

private:
    int dfs(TreeNode* root, int d, long long id, vector<long long>& ids) {

        if (root == nullptr) return 0;

        if (ids.size() == d) ids.push_back(id);
        return max(static_cast<int>(id - ids[d] + 1),
            max(dfs(root->left, d + 1, (id - ids[d]) * 2, ids),
                dfs(root->right, d + 1, (id - ids[d]) * 2 + 1, ids)));
    }
};