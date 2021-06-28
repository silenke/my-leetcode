#include <bits/stdc++.h>
using namespace std;

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

            ListNode* next1 = curr->next;
            ListNode* next2 = next1->next;
            next1->next = next2->next;

            next2->next = next1;
            curr->next = next2;
            
            curr = next1;
        }
        return dummyHead.next;
    }
};