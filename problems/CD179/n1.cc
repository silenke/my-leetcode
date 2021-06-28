#include "..\..\leetcode.h"

class Solution {
public:
    int maxDistance(TreeNode* root) {
        
        return dfs(root).second;
    }
    
private:
    pair<int, int> dfs(TreeNode* root) {
        // 以 root 为根节点的树（高度，最大距离）

        if (root == nullptr) return {0, 0};
        
        auto [lh, ln] = dfs(root->left);
        auto [rh, rn] = dfs(root->right);
        
        return {max(lh, rh) + 1, max(max(ln, rn), lh + rh + 1)};
    }
};