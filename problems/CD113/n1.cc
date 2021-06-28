#include "..\..\leetcode.h"

class Solution {
public:
    list_node* list_partition(list_node* head, int pivot) {
        
        list_node* h1 = nullptr;
        list_node* t1 = nullptr;
        list_node* h2 = nullptr;
        list_node* t2 = nullptr;
        list_node* h3 = nullptr;
        list_node* t3 = nullptr;
        
        list_node* curr = head;
        while (curr) {
            if (curr->val < pivot) {
                if (h1 == nullptr) h1 = curr;
                else t1->next = curr;
                t1 = curr;
            }
            else if (curr->val == pivot) {
                if (h2 == nullptr) h2 = curr;
                else t2->next = curr;
                t2 = curr;
            }
            else {
                if (h3 == nullptr) h3 = curr;
                else t3->next = curr;
                t3 = curr;
            }
            curr = curr->next;
        }
        
        list_node dummyHead;
        list_node* tail = &dummyHead;
        if (h1) {
            tail->next = h1;
            tail = t1;
        }
        if (h2) {
            tail->next = h2;
            tail = t2;
        }
        if (h3) {
            tail->next = h3;
            tail = t3;
        }
        tail->next = nullptr;
        
        return dummyHead.next;
    }
};