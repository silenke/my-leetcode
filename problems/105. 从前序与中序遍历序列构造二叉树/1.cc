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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        const int n = preorder.size();

        unordered_map<int, int> map;    // map[val]：val在inorder中的下标
        for (int i = 0; i < n; i++) {
            map[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1, map);
    }

private:
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,
        int pl, int pr, int il, int ir, unordered_map<int, int>& map)
    {
        if (pl > pr) return nullptr;

        int val = preorder[pl];
        TreeNode* root = new TreeNode(val);
        int mid = map[val];
        root->left = dfs(preorder, inorder, pl + 1, pl + mid - il, il, mid - 1, map);
        root->right = dfs(preorder, inorder, pl + mid - il + 1, pr, mid + 1, ir, map);
        return root;
    }
};