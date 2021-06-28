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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        dfs(root, target, K);
        return res;
    }

private:
    vector<int> res;

    int dfs(TreeNode* root, TreeNode* target, int k) {
        // 返回到target的距离，是否包含target

        if (root == nullptr) return -1;

        if (root == target) {
            find(root, k);
            return 0;
        }

        int l = dfs(root->left, target, k);
        if (l >= 0) {
            if (l + 1 == k) res.push_back(root->val);
            find(root->right, k - l - 2);
            return l + 1;
        }
        int r = dfs(root->right, target, k);
        if (r >= 0) {
            if (r + 1 == k) res.push_back(root->val);
            find(root->left, k - r - 2);
            return r + 1;
        }
        return -1;
    }

    void find(TreeNode* root, int k) {

        if (root == nullptr || k < 0) return;
        if (k == 0) res.push_back(root->val);
        find(root->left, k - 1);
        find(root->right, k - 1);
    }
};