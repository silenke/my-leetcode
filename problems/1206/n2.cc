#include "..\..\leetcode.h"

class Skiplist {
public:
    Skiplist() : root(new Node), level(0) {

    }
    
    bool search(int target) {

        Node* curr = root;
        for (int i = level; i >= 0; i--) {
            while (curr->rights[i] && target > curr->rights[i]->val) {
                curr = curr->rights[i];
            }
            if (curr->rights[i] && target == curr->rights[i]->val) {
                return true;
            }
        }
        return false;
    }

    void add(int num) {

        int l = 0;
        while (l <= level && rand() & 1) {
            l++;
        }
        if (l > level) {
            root->rights.emplace_back();
            level++;
        }
        
        Node* node = new Node(num, l);
        Node* curr = root;
        for (int i = level; i >= 0; i--) {
            while (curr->rights[i] && num > curr->rights[i]->val) {
                curr = curr->rights[i];
            }
            if (i <= l) {
                node->rights[i] = curr->rights[i];
                curr->rights[i] = node;
            }
        }
    }
    
    bool erase(int num) {

        Node* found = nullptr;
        Node* curr = root;
        for (int i = level; i >= 0; i--) {
            while (curr->rights[i] && num > curr->rights[i]->val) {
                curr = curr->rights[i];
            }
            if (curr->rights[i] && num == curr->rights[i]->val) {
                found = curr->rights[i];
                curr->rights[i] = found->rights[i];
            }
        }
        delete found;
        return found;
    }

private:
    struct Node {
        int val;
        vector<Node*> rights;
        Node() : val(-1), rights(1) {}
        Node(int val, int level) : val(val), rights(level + 1) {}
    };

    Node* root;
    int level;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */