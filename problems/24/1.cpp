#include "help.h"

// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *p = dummyHead;
        while (p->next && p->next->next) {

            ListNode *node1 = p->next;
            ListNode *node2 = node1->next;
            ListNode *next = node2->next;
            p->next = node2;
            node2->next = node1;
            node1->next = next;
            p = node1;
        }

        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 4};
    ListNode *head = createList(nums);
    printList(head);
    head = Solution().swapPairs(head);
    printList(head);
    destroyList(head);

    return 0;
}