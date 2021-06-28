#include "help.h"

using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        queue<TreeNode *> q;
        if (root)
            q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

int main() {

    return 0;
}