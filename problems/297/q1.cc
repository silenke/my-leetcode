#include "..\..\leetcode.h"

#include <string>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

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

        vector<TreeNode*> nodes;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            nodes.emplace_back(curr);
            if (curr) {
                q.emplace(curr->left);
                q.emplace(curr->right);
            }
        }

        int j = nodes.size() - 1;
        while (j >= 0 && nodes[j] == nullptr) {
            j--;
        }

        string res("[");
        for (int i = 0; i <= j; i++) {
            res += nodes[i] ? to_string(nodes[i]->val) + ',' : "null,";
        }
        res.back() = ']';
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        int i = 1;
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
    TreeNode* get(const string& data, int& i) {

        if (i >= data.size() || data[i] == 'n') {
            i += 5;
            return nullptr;
        }

        int sign = 1;
        while (data[i] == '-') {
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

int main() {

    TreeNode* root = Codec().deserialize("[1,2,3,null,null,4,5]");
    cout << Codec().serialize(root);

    return 0;
}