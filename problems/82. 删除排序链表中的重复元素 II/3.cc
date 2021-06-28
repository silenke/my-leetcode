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

        ListNode* next = head->next;
        if (head->val == next->val) {
            while (next && next->val == head->val) {
                delete head;
                head = next;
                next = next->next;
            }
            delete head;
            return deleteDuplicates(next);
        }
        head->next = deleteDuplicates(next);
        return head;;
    }
};