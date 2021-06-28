#include <bits/stdc++.h>
using namespace std;

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
    ListNode* reverseList(ListNode* head) {

        if (!head || !head->next) return head;

        ListNode* next = head->next;
        ListNode* newHead = reverseList(next);
        next->next = head;
        head->next = nullptr;
        return newHead;
    }
};