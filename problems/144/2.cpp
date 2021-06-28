#include "help.h"

using namespace std;

// Time complexity: O(n)
// Space complexity: O(h)

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;

        stack<Command> stack;
        if (root)
            stack.push(Command("go", root));
        while (!stack.empty()) {
            Command command = stack.top();
            stack.pop();
            if (command.s == "go") {
                if (command.node->right)
                    stack.push(Command("go", command.node->right));
                if (command.node->left)
                    stack.push(Command("go", command.node->left));
                stack.push(Command("visit", command.node));
            }
            else
                ans.push_back(command.node->val);
        }

        return ans;
    }

private:
    struct Command {
        string s;
        TreeNode *node;
        Command(string s, TreeNode *node) : s(s), node(node){}
    };
};

int main() {
    
    return 0;
}