#include "..\..\leetcode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        if (!head || !head->next) return head;

        ListNode dummy(0, head);
        ListNode* tail = head;
        ListNode* curr = head->next;
        while (curr) {
            if (curr->val >= tail->val) {
                tail = curr;
            }
            else {
                ListNode* prev = &dummy;
                while (prev->next->val < curr->val) {
                    prev = prev->next;
                }
                tail->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }
            curr = tail->next;
        }
        return dummy.next;
    }
};