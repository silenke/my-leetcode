#include "..\..\leetcode.h"

class Solution {
public:
    int countNodes(TreeNode* root) {

        int res = 0;
        int h = height(root);
        while (root) {
            if (height(root->right) == h - 1) {
                res += (1 << (h - 1));
                root = root->right;
            }
            else {
                res += (1 << (h - 2));
                root = root->left;
            }
            h--;
        }
        return res;
    }

private:
    int height(TreeNode* root) {
        
        int h = 0;
        while (root) {
            h++;
            root = root->left;
        }
        return h;
    }
};