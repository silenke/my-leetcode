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
        
        string res("[");
        preOrderSerialize(root, res);
        res.back() = ']';
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int i = 1;
        return preOrderDeserialize(data, i);
    }

private:
    void preOrderSerialize(TreeNode* root, string& res) {

        if (root == nullptr) {
            res += "null,";
            return;
        }
        
        res += to_string(root->val) + ',';
        preOrderSerialize(root->left, res);
        preOrderSerialize(root->right, res);
    }

    TreeNode* preOrderDeserialize(const string& data, int& i) {

        TreeNode* root = getNode(data, i);
        if (root == nullptr) return nullptr;
        
        root->left = preOrderDeserialize(data, i);
        root->right = preOrderDeserialize(data, i);
        return root;
    }

    TreeNode* getNode(const string& data, int& i) {
        
        if (i >= data.size() || data[i] == 'n') {
            i += 5;
            return nullptr;
        }
        int flag = 1;
        if (data[i] == '-') {
            flag = -1;
            i++;
        }
        int val = 0;
        while (isdigit(data[i])) {
            val = val * 10 + data[i] - '0';
            i++;
        }
        i++;
        return new TreeNode(flag *val);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));