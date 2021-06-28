#include "help.h"

// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *curr = dummyHead;
        while (curr->next) {
            if (curr->next->val == val) {
                ListNode *temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            else
                curr = curr->next;
        }

        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

int main() {

    vector<int> nums = {1, 2, 6, 3, 4, 5, 6};
    ListNode *head = createList(nums);
    printList(head);
    head = Solution().removeElements(head, 6);
    printList(head);
    destroyList(head);

    return 0;
}