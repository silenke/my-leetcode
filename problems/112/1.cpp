#include <iostream>

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
    bool hasPathSum(TreeNode* root, int sum) {
        
        if (!root)
            return false;

        if (!root->left && !root->right)
            return root->val == sum;

        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};

int main() {

    return 0;
}