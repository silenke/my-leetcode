#include "help.h"

// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = createList(nums);
    printList(head);
    head = Solution().reverseList(head);
    printList(head);
    destroyList(head);

    return 0;
}