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
        
        if (lists.empty()) return nullptr;

        for (int i = 1; i < lists.size(); i *= 2) { // i += i
            for (int j = 0; j + i < lists.size(); j += i * 2) { // j += i + i
                lists[j] = mergeTowLists(lists[j], lists[j + i]);
            }
        }
        return lists.front();
    }

private:
    ListNode* mergeTowLists(ListNode* l1, ListNode* l2) {

        ListNode dummy;
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val > l2->val) swap(l1, l2);
            tail = tail->next = l1;
            l1 = l1->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};