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
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if (curr == nullptr) {
                res += "#,";
            }
            else {
                res += to_string(curr->val) + ',';
                q.emplace(curr->left);
                q.emplace(curr->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int i = 0;
        TreeNode* root = get(data, i);
        queue<TreeNode*> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            if ((curr->left = get(data, i))) q.emplace(curr->left);
            if ((curr->right = get(data, i))) q.emplace(curr->right);
        }
        return root;
    }

private:
    TreeNode* get(string data, int& i) {
        
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