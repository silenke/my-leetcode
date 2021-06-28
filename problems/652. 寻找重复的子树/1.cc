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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        unordered_map<long long, int> ids;
        unordered_map<int, int> counts;
        vector<TreeNode*> res;
        dfs(root, ids, counts, res);
        return res;
    }

private:
    int dfs(TreeNode* root, unordered_map<long long, int>& ids,
        unordered_map<int, int>& counts, vector<TreeNode*>& res)
    {
        if (root == nullptr) return 0;

        long long key = (static_cast<unsigned long long>(root->val) << 32) |
            (dfs(root->left, ids, counts, res) << 16) |
            (dfs(root->right, ids, counts, res));

        int id;
        auto it = ids.find(key);
        if (it != ids.end()) {
            id = it->second;
        }
        else {
            id = ids[key] = ids.size() + 1;
        }
        if (++counts[id] == 2) res.push_back(root);
        return id;
    }
};