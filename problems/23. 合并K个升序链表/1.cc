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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        auto cmp = [](ListNode* a, ListNode* b){ return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        ListNode dummy;
        ListNode* tail = &dummy;
        for (ListNode* head : lists) {
            if (head) pq.push(head);
        }
        while (!pq.empty()) {
            tail = tail->next = pq.top(); pq.pop();
            if (tail->next) pq.push(tail->next);
        }
        return dummy.next;
    }
};