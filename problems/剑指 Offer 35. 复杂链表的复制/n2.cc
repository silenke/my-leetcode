#include "..\..\leetcode.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if (!head) return nullptr;

        Node* curr = head;
        while (curr) {
            curr->next = new Node(curr->val, curr->next);
            curr = curr->next->next;
        }

        curr = head;
        while (curr) {
            curr->next->random = curr->random ? curr->random->next : nullptr;
            curr = curr->next->next;
        }
        
        Node* res = head->next;
        curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = next->next;
            next->next = curr->next ? curr->next->next : nullptr;
            curr = curr->next;
        }
        return res;
    }
};