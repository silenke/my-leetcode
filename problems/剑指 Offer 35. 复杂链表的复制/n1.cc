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
        
        unordered_map<Node*, Node*> map;
        for (Node* curr = head; curr; curr = curr->next) {
            map[curr] = new Node(curr->val);
        }
        for (Node* curr = head; curr; curr = curr->next) {
            map[curr]->next = map[curr->next];
            map[curr]->random = map[curr->random];
        }
        return map[head];
    }
};