#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Time complexity: O(n)
// Space complexity: O(h)

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        if (!root)
            return {};
        if (!root->left && !root->right)
            return {to_string(root->val)};

        vector<string> ans;
        vector<string> left = binaryTreePaths(root->left);
        for (string &s : left)
            ans.push_back(to_string(root->val) + "->" + s);
        vector<string> right = binaryTreePaths(root->right);
        for (string &s : right)
            ans.push_back(to_string(root->val) + "->" + s);

        return ans;
    }
};

int main() {

    return 0;
}