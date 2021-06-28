#include "..\..\leetcode.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        unordered_map<TreeNode*, TreeNode*> parents;
        queue<TreeNode*> que;
        parents[root] = nullptr;
        if (root) que.emplace(root);
        while (!parents.count(p) || !parents.count(q)) {
            root = que.front(); que.pop();
            if (root->left) {
                parents[root->left] = root;
                que.emplace(root->left);
            }
            if (root->right) {
                parents[root->right] = root;
                que.emplace(root->right);
            }
        }
        unordered_set<TreeNode*> set;
        while (p) {
            set.insert(p);
            p = parents[p];
        }
        while (!set.count(q)) {
            q = parents[q];
        }
        return q;
    }
};