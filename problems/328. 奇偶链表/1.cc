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
    ListNode* oddEvenList(ListNode* head) {

        if (!head || !head->next) return head;

        ListNode* head2 = head->next;
        ListNode* curr = head;
        while (curr->next && curr->next->next) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = next->next->next;
            curr = curr->next;
        }
        curr->next = head2;
        return head;
    }
};