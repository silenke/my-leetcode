#include "..\..\leetcode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {

        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        while (prev->next && prev->next->val != val) {
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        prev->next = curr->next;
        // delete curr;
        return dummy.next;
    }
};