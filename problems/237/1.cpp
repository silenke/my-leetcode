#include "help.h"

using namespace std;

// Time complexity: O(1)
// Space complexity: O(1)

class Solution {
public:
    void deleteNode(ListNode* node) {

        ListNode *next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete next;
    }
};

int main() {

    vector<int> nums = {4, 5, 1, 9};
    ListNode *head = createList(nums);
    printList(head);
    Solution().deleteNode(head->next);
    printList(head);

    return 0;
}