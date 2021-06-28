#include "..\..\leetcode.h"

class Skiplist {
public:
    Skiplist() : head(new Node), level(0) {

    }
    
    bool search(int target) {

        Node* curr = head;
        for (int i = level; i >= 0; i--) {
            while (curr->rights[i] && curr->rights[i]->val < target) {
                curr = curr->rights[i];
            }
            if (curr->rights[i] && curr->rights[i]->val == target) {
                return true;
            }
        }
        return false;
    }
    
    void add(int num) {

        int j = 0;
        while (j <= level && (rand() & 1)) {
            j++;
        }
        if (j > level) {
            head->rights.emplace_back(nullptr);
            level++;
        }
        Node* node = new Node(num, j + 1);
        Node* curr = head;
        for (int i = level; i >= 0; i--) {
            while (curr->rights[i] && curr->rights[i]->val < num) {
                curr = curr->rights[i];
            }
            if (i <= j) {
                node->rights[i] = curr->rights[i];
                curr->rights[i] = node;
            }
        }
    }
    
    bool erase(int num) {

        Node* node = nullptr;
        Node* curr = head;
        for (int i = level; i >= 0; i--) {
            while (curr->rights[i] && curr->rights[i]->val < num) {
                curr = curr->rights[i];
            }
            if (curr->rights[i] && curr->rights[i]->val == num) {
                node = curr->rights[i];
                curr->rights[i] = node->rights[i];
            }
        }
        delete node;
        return node;
    }

private:
    struct Node {
        int val;
        vector<Node*> rights;
        Node() : val(-1) , rights(1, nullptr) {}
        Node(int val, int size) : val(val), rights(size, nullptr) {}
    };

    Node* head;
    int level;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */