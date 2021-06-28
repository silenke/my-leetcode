#include "..\..\leetcode.h"

#include <iostream>
#include <cstdio>
using namespace std;

struct list_node {
    int val;
    struct list_node* next;
};

int pivot;

list_node* input_list(void)
{
    int n, val;
    list_node* phead = new list_node();
    list_node* cur_pnode = phead;
    cin >> n >> pivot;
    for (int i = 1; i <= n; ++i) {
        cin >> val;
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node* new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}

void output_list(list_node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}

list_node* list_partition(list_node* head, int pivot)
{
    //////在下面完成代码
    list_node* p1 = nullptr;
    list_node* p2 = nullptr;
    list_node* p3 = nullptr;
    list_node* q1 = nullptr;
    list_node* q2 = nullptr;
    list_node* q3 = nullptr;

    list_node* curr = head;
    while (curr) {
        if (curr->val < pivot) {
            if (!p1) p1 = curr;
            else q1->next = curr;
            q1 = curr;
        }
        else if (curr->val == pivot) {
            if (!p2) p2 = curr;
            else q2->next = curr;
            q2 = curr;
        }
        else {
            if (!p3) p3 = curr;
            else q3->next = curr;
            q3 = curr;
        }
        curr = curr->next;
    }

    list_node dummyHead;
    list_node* tail = &dummyHead;
    if (p1) {
        tail->next = p1;
        tail = q1;
    }
    if (p2) {
        tail->next = p2;
        tail = q2;
    }
    if (p3) {
        tail->next = p3;
        tail = q3;
    }
    tail->next = nullptr;
    return dummyHead.next;
}


int main()
{
    list_node* head = input_list();
    output_list(list_partition(head, pivot));
    return 0;
}