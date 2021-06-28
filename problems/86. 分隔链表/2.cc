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
    ListNode* partition(ListNode* head, int x) {

        ListNode dummy(0, head);
        ListNode* last = &dummy;
        ListNode* prev = &dummy;
        while (prev->next) {
            ListNode* curr = prev->next;
            if (curr->val < x) {
                if (last == prev) {
                    prev = curr;
                }
                else {
                    prev->next = curr->next;
                    curr->next = last->next;
                    last->next = curr;
                }
                last = curr;
            }
            else {
                prev = curr;
            }
        }
        return dummy.next;
    }
};