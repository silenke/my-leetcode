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
        serialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int i = 0;
        return deserialize(data, i);
    }

private:
    void serialize(TreeNode* root, string& res) {

        if (root == nullptr) {
            res += "#,";
            return;
        }

        res += to_string(root->val) + ',';
        serialize(root->left, res);
        serialize(root->right, res);
    }

    TreeNode* deserialize(string& data, int& i) {

        TreeNode* root = get(data, i);
        if (root) {
            root->left = deserialize(data, i);
            root->right = deserialize(data, i);
        }
        return root;
    }

    TreeNode* get(string& data, int& i) {

        if (data[i] == '#') {
            i += 2;
            return nullptr;
        }

        int sign = 1;
        if (data[i] == '-') {
            sign = -1;
            i++;
        }
        int val = 0;
        while (data[i] != ',') {
            val = val * 10 + (data[i++] - '0');
        }
        i++;
        return new TreeNode(sign * val);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));