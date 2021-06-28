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
    int maxDepth(TreeNode* root) {
        
        if (root == NULL)
            return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main() {

    return 0;
}