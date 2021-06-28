#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createList(vector<int> &nums);

void destroyList(ListNode *head);

void printList(ListNode *head);

ListNode *createList(vector<int> &nums) {

    if (nums.size() <= 0)
        return NULL;

    ListNode *head= new ListNode(nums[0]);
    ListNode *curr = head;
    for (int i = 1; i < nums.size(); i++) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }

    return head;
}

void destroyList(ListNode *head) {

    ListNode *curr = head;
    while (curr) {
        ListNode *temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void printList(ListNode *head) {

    for (ListNode *curr = head; curr; curr = curr->next)
        cout << curr->val << "->";
    cout << "NULL" << endl;
}