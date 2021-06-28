#include "help.h"

// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        while (head != NULL && head->val == val) {
            ListNode *temp = head;
            head = temp->next;
            delete temp;
        }

        if (head == NULL)
            return NULL;

        ListNode *curr = head;
        while (curr->next != NULL) {
            if (curr->next->val == val) {
                ListNode *temp = curr->next;
                curr->next = temp->next;
                delete temp;
            }
            else
                curr = curr->next;
        }

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