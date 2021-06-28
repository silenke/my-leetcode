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

        if (head == nullptr) return nullptr;

        Node* curr = head;
        while (curr) {
            curr->next = new Node(curr->val, curr->next, nullptr);
            curr = curr->next->next;
        }

        curr = head;
        while (curr) {
            if (curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        Node* res = head->next;
        curr = head;
        Node* next = head->next;
        while (next->next) {
            curr = curr->next = next->next;
            next = next->next = curr->next;
        }
        curr->next = nullptr;
        return res;
    }
};