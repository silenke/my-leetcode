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
    ListNode* swapPairs(ListNode* head) {

        ListNode dummyHead(0, head);

        ListNode* curr = &dummyHead;
        while (curr->next && curr->next->next) {

            ListNode* node1 = curr->next;
            ListNode* node2 = node1->next;

            node1->next = node2->next;
            node2->next = node1;
            curr->next = node2;

            curr = node1;
        }
        return dummyHead.next;
    }
};