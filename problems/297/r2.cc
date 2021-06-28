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
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode* root, ostringstream& out) {

        char status = root ? 1 : 0;
        out.write(&status, sizeof(status));
        if (root == nullptr) return;

        out.write(reinterpret_cast<char*>(&(root->val)), sizeof(root->val));
        serialize(root->left, out);
        serialize(root->right, out);
    }

    TreeNode* deserialize(istringstream& in) {

        char status;
        in.read(&status, sizeof(status));
        if (status == 0) return nullptr;

        int val;
        in.read(reinterpret_cast<char*>(&val), sizeof(val));
        TreeNode* root = new TreeNode(val);

        root->left = deserialize(in);
        root->right = deserialize(in);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));