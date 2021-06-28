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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        unordered_map<TreeNode*, TreeNode*> map;
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q;
        if (root) q.emplace(root, targetSum);
        map[root] = nullptr;
        while (!q.empty()) {
            auto [node, sum] = q.front(); q.pop();
            sum -= node->val;
            if (node->left == nullptr && node->right == nullptr) {
                if (sum == 0) {
                    vector<int> tmp;
                    while (node) {
                        tmp.emplace_back(node->val);
                        node = map[node];
                    }
                    reverse(tmp.begin(), tmp.end());
                    res.emplace_back(tmp);
                }
                continue;
            }
            if (node->left) {
                q.emplace(node->left, sum);
                map[node->left] = node;
            }
            if (node->right) {
                q.emplace(node->right, sum);
                map[node->right] = node;
            }
        }
        return res;
    }
};