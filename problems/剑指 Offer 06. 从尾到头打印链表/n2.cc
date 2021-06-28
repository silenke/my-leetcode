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
    vector<int> reversePrint(ListNode* head) {

        vector<int> res;
        function<void(ListNode*)> dfs = [&](ListNode* head) {
            if (!head) return;
            dfs(head->next);
            res.emplace_back(head->val);
        };
        dfs(head);
        return res;
    }
};