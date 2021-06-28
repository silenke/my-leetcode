#include "..\..\leetcode.h"

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() : head(new Node), tail(new Node), size(0) {

        head->next = tail;
        tail->prev = head;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {

        if (index < 0 || index >= size) return -1;

        int k = size - 1 - index;
        if (index < k) {       
            Node* curr = head->next;
            while (index--) {
                curr = curr->next;
            }
            return curr->val;
        }
        Node* curr = tail->prev;
        while (k--) {
            curr = curr->prev;
        }
        return curr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {

        head->next = new Node(val, head, head->next);
        head->next->next->prev = head->next;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {

        tail->prev = new Node(val, tail->prev, tail);
        tail->prev->prev->next = tail->prev;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {

        if (index > size) return;
        if (index == size) return addAtTail(val);
        if (index <= 0) return addAtHead(val);

        int k = size - index;
        if (index < k) {
            Node* curr = head;
            while (index--) {
                curr = curr->next;
            }
            curr->next = new Node(val, curr, curr->next);
            curr->next->next->prev = curr->next;
        }
        else {
            Node* curr = tail;
            while (k--) {
                curr = curr->prev;
            }
            curr->prev = new Node(val, curr->prev, curr);
            curr->prev->prev->next = curr->prev;
        }
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {

        if (index < 0 || index >= size) return;

        int k = size - 1 - index;
        if (index < k) {
            Node* curr = head;
            while (index--) {
                curr = curr->next;
            }
            Node* next = curr->next;
            curr->next = next->next;
            next->next->prev = curr;
            delete next;
        }
        else {
            Node* curr = tail;
            while (k--) {
                curr = curr->prev;
            }
            Node* prev = curr->prev;
            curr->prev = prev->prev;
            prev->prev->next = curr;
            delete prev;
        }
        size--;
    }

private:
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node() : val(0), prev(nullptr), next(nullptr) {}
        Node(int val) : val(val), prev(nullptr), next(nullptr) {}
        Node(int val, Node* prev, Node* next) : val(val), prev(prev), next(next) {}
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