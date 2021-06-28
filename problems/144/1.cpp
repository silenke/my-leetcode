#include "help.h"

using namespace std;

// Time complexity: O(n)
// Space complexity: O(h)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;
        preorderTraversal(root, ans);
        return ans;
    }

private:
    void preorderTraversal(TreeNode *node, vector<int> &ans) {

        if (node) {
            ans.push_back(node->val);
            preorderTraversal(node->left, ans);
            preorderTraversal(node->right, ans);
        }
    }
};

int main() {
    
    return 0;
}