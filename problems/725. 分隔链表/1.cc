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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {

        int len = 0;
        for (ListNode* p = root; p; p = p->next) len++;
        int l = len / k;
        int r = len % k;
        vector<ListNode*> res(k);
        ListNode* prev = nullptr;
        ListNode* curr = root;
        for (int i = 0; i < k; i++, r--) {
            res[i] = curr;
            for (int j = 0; j < l + (r > 0); j++) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
        }
        return res;
    }
};