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
    TreeNode* invertTree(TreeNode* root) {
        
        if (root == NULL)
            return NULL;

        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        swap(root->left, root->right);

        return root;
    }
};

int main() {

    return 0;
}