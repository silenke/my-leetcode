#include "help.h"

using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        queue<pair<TreeNode *, int>> q;
        if (root)
            q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode *node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level == ans.size())
                ans.push_back(vector<int>());

            ans[level].push_back(node->val);
            if (node->left)
                q.push(make_pair(node->left, level + 1));
            if (node->right)
                q.push(make_pair(node->right, level + 1));
        }

        return ans;
    }
};

int main() {

    return 0;
}