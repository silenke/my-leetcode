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
    ListNode* sortList(ListNode* head) {

        if (!head || !head->next) return head;

        int size = 1;
        ListNode* curr = head;
        while (curr = curr->next) size++;

        ListNode dummyHead(0, head);
        for (int i = 1; i < size; i *= 2) {
            ListNode* curr = dummyHead.next;
            ListNode* tail = &dummyHead;
            while (curr) {
                ListNode* l = curr;
                ListNode* r = split(l, i);
                curr = split(r, i);
                auto [h, t] = merge(l, r);
                tail->next = h;
                tail = t;
            }
        }
        return dummyHead.next;
    }

private:
    ListNode* split(ListNode* head, int n) {

        while (--n && head) {
            head = head->next;
        }
        ListNode* rest = head ? head->next : nullptr;
        if (head) head->next = nullptr;
        return rest;
    }

    pair<ListNode*, ListNode*> merge(ListNode* l1, ListNode* l2) {
        
        ListNode dummyHead;
        ListNode* tail = &dummyHead;
        while (l1 && l2) {
            if (l1->val > l2->val) swap(l1, l2);
            tail = tail->next = l1;
            l1 = l1->next;
        }
        tail->next = l1 ? l1 : l2;
        while (tail->next) {
            tail = tail->next;
        }
        return {dummyHead.next, tail};
    }
};