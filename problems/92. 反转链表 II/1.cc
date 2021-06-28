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
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        if (m == n) return head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* curr = head;
        for (int i = 0; i < m - 1; i++) {
            prev = curr;
            curr = curr->next;
        }
        ListNode* tail = curr;
        for (int i = 0; i < n - m + 1; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tail->next->next = prev;
        tail->next = curr;
        return dummy.next;
    }
};