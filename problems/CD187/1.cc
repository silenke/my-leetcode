#include "..\..\leetcode.h"

#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> childs;
};

class Solution {
public:
    int maxHappy(TreeNode* root) {
        
        auto [a, b] = dfs(root);
        return max(a, b);
    }
    
private:
    pair<int, int> dfs(TreeNode* root) {
        // 以 root 为根节点的树（参加，不参加）

        if (root == nullptr) return {0, 0};
        
        int a = root->val, b = 0;
        for (TreeNode* c : root->childs) {
            auto [p, q] = dfs(c);
            a += q;
            b += max(p ,q);
        }
        return {a, b};
    }
};

int main() {
    
    int n, root;
    cin >> n >> root;
    
    vector<TreeNode*> nodes(n + 1, nullptr);
    for (int i = 1; i <= n; i++) {
        nodes[i] = new TreeNode;
        cin >> nodes[i]->val;
    }
    
    while (--n) {
        int father, child;
        cin >> father >> child;
        nodes[father]->childs.emplace_back(nodes[child]);
    }
    
    cout << Solution().maxHappy(nodes[root]);
    
    return 0;
}