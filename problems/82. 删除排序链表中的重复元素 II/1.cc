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
    ListNode* deleteDuplicates(ListNode* head) {

        if (!head || !head->next) return head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        while (prev->next) {
            ListNode* curr = prev->next;
            int val = curr->val;
            if (curr->next && curr->next->val == val) {
                while (curr && curr->val == val) {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
            }
            else {
                prev = curr;
            }
        }
        return dummy.next;
    }
};