#include "..\..\leetcode.h"

#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDistance(TreeNode* root) {
        
        return dfs(root).first;
    }
    
private:
    pair<int, int> dfs(TreeNode* root) {
        // 以 root 为根节点的树（最大距离，高度）
        
        if (root == nullptr) return {0, 0};
        
        auto [ld, lh] = dfs(root->left);
        auto [rd, rh] = dfs(root->right);
        
        return {max(max(ld, rd), lh + rh + 1), max(lh, rh) + 1};
    }
};

int main() {
    
    int n, root;
    cin >> n >> root;
    
    vector<TreeNode*> nodes(n + 1, nullptr);
    for (int i = 1; i <= n; i++) {
        nodes[i] = new TreeNode;
    }
    
    for (int i = 1; i <= n; i++) {
        int node, left, right;
        cin >> node >> left >> right;
        nodes[node]->left = nodes[left];
        nodes[node]->right = nodes[right];
    }
    
    cout << Solution().maxDistance(nodes[root]);
    
    return 0;
}