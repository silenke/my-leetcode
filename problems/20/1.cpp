#include <iostream>
#include <stack>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    bool isValid(string s) {

        stack<char> stack;
        for (char &c : s) {
            switch (c) {
                case '(':
                    stack.push(')');
                    break;
                case '[':
                    stack.push(']');
                    break;
                case '{':
                    stack.push('}');
                    break;
                default:
                    if (!stack.empty() && stack.top() == c)
                        stack.pop();
                    else
                        return false;
            }
        }

        return stack.empty();
    }
};

int main() {

    string s = "{[]}";
    cout << Solution().isValid(s) << endl;

    return 0;
}