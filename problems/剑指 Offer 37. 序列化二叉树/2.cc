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
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            root = q.front(); q.pop();
            char status = root ? 1 : 0;
            out.write(&status, sizeof(status));
            if (!root) continue;
            out.write(reinterpret_cast<const char*>(&root->val), sizeof(root->val));
            q.emplace(root->left);
            q.emplace(root->right);
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        istringstream in(data);
        function<TreeNode*(void)> getNode = [&]() {
            char status;
            in.read(&status, sizeof(status));
            if (!status) return static_cast<TreeNode*>(nullptr);
            int val;
            in.read(reinterpret_cast<char*>(&val), sizeof(val));
            return new TreeNode(val);
        };
        TreeNode* root = getNode();
        queue<TreeNode*> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if (curr->left = getNode()) q.emplace(curr->left);
            if (curr->right = getNode()) q.emplace(curr->right);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));