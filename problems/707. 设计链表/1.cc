#include "..\..\leetcode.h"

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() : head(new Node), tail(head), size(0) {

    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {

        if (index < 0 || index >= size) return -1;

        Node* curr = head->next;
        while (index--) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {

        head->next = new Node(val, head->next);
        if (size++ == 0) tail = head->next;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {

        tail = tail->next = new Node(val);
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {

        if (index > size) return;
        if (index == size) return addAtTail(val);
        if (index <= 0) return addAtHead(val);

        Node* curr = head;
        while (index--) {
            curr = curr->next;
        }
        curr->next = new Node(val, curr->next);
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {

        if (index < 0 || index >= size) return;

        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        Node* next = curr->next;
        curr->next = next->next;
        delete next;
        if (index == --size) {
            tail = curr;
        }
    }

private:
    struct Node {
        int val;
        Node* next;
        Node() : val(0), next(nullptr) {}
        Node(int val) : val(val), next(nullptr) {}
        Node(int val, Node* next) : val(val), next(next) {}
    };

    Node* head;
    Node* tail;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */