#include "help.h"

using namespace std;

// Time complexity: O(n)
// Space complexity: O(h)

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;
        postorderTraversal(root, ans);
        return ans;
    }

private:
    void postorderTraversal(TreeNode *node, vector<int> &ans) {

        if (node) {
            postorderTraversal(node->left, ans);
            postorderTraversal(node->right, ans);
            ans.push_back(node->val);
        }
    }
};

int main() {

    return 0;
}