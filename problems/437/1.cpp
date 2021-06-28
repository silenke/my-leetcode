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
    int pathSum(TreeNode* root, int sum) {
        
        if (root == NULL)
            return 0;

        return findPath(root, sum) +
               pathSum(root->left, sum) +
               pathSum(root->right, sum);
    }

private:
    int findPath(TreeNode *root, int sum) {

        if (root == NULL)
            return 0;

        return (root->val == sum) +
               findPath(root->left, sum - root->val) +
               findPath(root->right, sum - root->val);
    }
};

int main() {

    return 0;
}