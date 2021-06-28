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
    ListNode* removeElements(ListNode* head, int val) {

        ListNode dummyHead(0, head);

        ListNode* curr = &dummyHead;
        while (curr->next) {
            ListNode* next = curr->next;
            if (next->val == val) {
                curr->next = next->next;
                delete next;
            }
            else {
                curr = next;
            }
        }
        return dummyHead.next;
    }
};