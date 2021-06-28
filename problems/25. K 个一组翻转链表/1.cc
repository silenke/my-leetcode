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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0, head);
        int n = 0;
        while (head) {
            n++;
            head = head->next;
        }

        ListNode* last = &dummy;
        for (int i = 0; i < n / k; i++) {
            ListNode* prev = last->next;
            for (int j = 0; j < k - 1; j++) {
                ListNode* curr = prev->next;    // 要移动的节点
                prev->next = curr->next;
                curr->next = last->next;
                last->next = curr;
            }
            last = prev;
        }
        return dummy.next;
    }
};