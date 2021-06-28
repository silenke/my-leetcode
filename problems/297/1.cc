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
        
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node) {
                res += to_string(node->val) + ",";
                q.emplace(node->left);
                q.emplace(node->right);
            }
            else {
                res += "null,";
            }
        }
        res.back() = ']';
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int i = 1;
        TreeNode* root = getNode(data, i);

        queue<TreeNode*> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            node->left = getNode(data, i);
            node->right = getNode(data, i);
            if (node->left) q.emplace(node->left);
            if (node->right) q.emplace(node->right);
        }
        return root;
    }

private:
    TreeNode* getNode(const string& data, int& i) {

        if (i >= data.size() || data[i] == 'n') {
            i += 5;
            return nullptr;
        }
        int flag = 1;
        if (data[i] == '-') {
            i++;
            flag = -1;
        }
        int val = 0;
        while (isdigit(data[i])) {
            val = val * 10 + data[i] - '0';
            i++;
        }
        i++;
        return new TreeNode(flag * val);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));