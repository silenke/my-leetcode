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
        
        ostringstream out;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            char status = root ? 1 : 0;
            out.write(&status, sizeof status);
            if (!root) return;
            out.write(reinterpret_cast<const char*>(&root->val), sizeof root->val);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        istringstream in(data);
        function<TreeNode*(void)> dfs = [&]() -> TreeNode* {
            char status;
            in.read(&status, sizeof status);
            if (!status) return nullptr;
            int val;
            in.read(reinterpret_cast<char*>(&val), sizeof val);
            return new TreeNode(val, dfs(), dfs());
        };
        return dfs();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));