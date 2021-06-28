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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode dummy;
        int c = 0;
        while (!s1.empty() || !s2.empty() || c > 0) {
            if (!s1.empty()) c += s1.top(), s1.pop();
            if (!s2.empty()) c += s2.top(), s2.pop();
            dummy.next = new ListNode(c % 10, dummy.next);
            c /= 10;
        }
        return dummy.next;
    }
};