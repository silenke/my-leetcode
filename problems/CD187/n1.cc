#include "..\..\leetcode.h"

class Solution {
public:
    int maxHappy(TreeNode* root) {
        
        auto [a, b] = dfs(root);
        return max(a, b);
    }
    
private:
    
    pair<int, int> dfs(TreeNode* root) {
        // 以 root 为根的树（参加，不参加）的最大快乐值
        
        if (root == nullptr) return {0, 0};
        
        int a = root->val, b = 0;
        for (TreeNode* c : root->childs) {
            auto [p, q] = dfs(c);
            a += q;
            b += max(p, q);
        }
        return {a, b};
    }
};