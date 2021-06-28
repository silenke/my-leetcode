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
            root = q.front(); q.pop();
            if (root) {
                res += to_string(root->val) + ",";
                q.emplace(root->left);
                q.emplace(root->right);
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
            TreeNode* curr = q.front(); q.pop();
            if ((curr->left = getNode(data, i))) q.emplace(curr->left);
            if ((curr->right = getNode(data, i))) q.emplace(curr->right);
        }
        return root;
    }

private:
    TreeNode* getNode(const string& data, int& i) {
        
        if (data[i] == 'n') {
            i += 5;
            return nullptr;
        }
        
        int sign = 1;
        if (data[i] == '-') {
            sign = -1;
            i++;
        }
        int val = 0;
        while (isdigit(data[i])) {
            val = val * 10 + (data[i++] - '0');
        }
        i++;
        return new TreeNode(sign * val);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));