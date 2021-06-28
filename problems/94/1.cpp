#include "help.h"

using namespace std;

// Time complexity: O(n)
// Space complexity: O(h)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        inorderTraversal(root, ans);
        return ans;
    }

private:
    void inorderTraversal(TreeNode *node, vector<int> &ans) {

        if (node) {
            inorderTraversal(node->left, ans);
            ans.push_back(node->val);
            inorderTraversal(node->right, ans);
        }
    }
};

int main() {

    return 0;
}