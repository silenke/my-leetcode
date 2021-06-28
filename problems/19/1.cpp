#include "help.h"

using namespace std;

// Time complexity: O(m)
// Space complexity: O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *p = dummyHead;
        ListNode *q = dummyHead;
        for (int i = 0; i < n + 1; i++)
            q = q->next;

        while (q) {
            p = p->next;
            q = q->next;
        }
        ListNode *delNode = p->next;
        p->next = delNode->next;
        delete delNode;

        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

int main() {

    vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = createList(nums);
    printList(head);
    head = Solution().removeNthFromEnd(head, 2);
    printList(head);

    return 0;
}