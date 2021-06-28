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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string res;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if (!root) return;
            res.append(reinterpret_cast<const char*>(&root->val), sizeof root->val);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int pos = 0;
        function<TreeNode*(int, int)> dfs = [&](int l, int r) -> TreeNode* {
            if (pos >= data.size()) return nullptr;
            int val = *reinterpret_cast<const int*>(data.size() + pos);
            if (val <= l || val >= r) return nullptr;
            pos += sizeof val;
            // return new TreeNode(val, dfs(l, val), dfs(val, r));
            TreeNode* root = new TreeNode(val);
            root->left = dfs(l, val);
            root->right = dfs(val, r);
            return root;
        };
        return dfs(INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;