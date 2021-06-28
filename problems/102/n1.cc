#include <bits/stdc++.h>
using namespace std;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;

        queue<TreeNode*> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            vector<int> tmp;
            int n = q.size();
            for (int i = 0; i < n; i++) {     
                TreeNode* node = q.front();
                q.pop();
                tmp.emplace_back(node->val);
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};