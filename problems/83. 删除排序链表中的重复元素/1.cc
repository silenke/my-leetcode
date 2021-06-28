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

        ListNode* prev = head;
        while (prev->next) {
            ListNode* curr = prev->next;
            if (curr->val == prev->val) {
                prev->next = curr->next;
                delete curr;
            }
            else {
                prev = curr;
            }
        }
        return head;
    }
};