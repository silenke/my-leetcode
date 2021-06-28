#include "..\..\leetcode.h"

class Skiplist {
public:
    Skiplist() : head(new Node) {

    }
    
    bool search(int target) {

        Node* curr = head;
        while (curr) {
            while(curr->right && curr->right->val < target) {
                curr = curr->right;
            }
            if (curr->right && curr->right->val == target) {
                return true;
            }
            curr = curr->down;
        }
        return false;
    }
    
    void add(int num) {

        stack<Node*> s;
        Node* curr = head;
        while (curr) {
            while (curr->right && curr->right->val < num) {
                curr = curr->right;
            }
            s.emplace(curr);
            curr = curr->down;
        }

        bool insert = true;
        Node* down = nullptr;
        while (!s.empty() && insert) {
            Node* curr = s.top(); s.pop();
            Node* right = curr->right;
            curr->right = new Node(num, right, down);
            down = curr->right;
            insert = rand() & 1;
        }
        
        if (insert) {
            head = new Node(-1, new Node(num, nullptr, down), head);
        }
    }
    
    bool erase(int num) {

        bool found = false;
        Node* curr = head;
        while (curr) {
            while (curr->right && curr->right->val < num) {
                curr = curr->right;
            }
            if (curr->right && curr->right->val == num) {
                found = true;
                Node* right = curr->right;
                curr->right = right->right;
                delete right;
            }
            curr = curr->down;
        }
        return found;
    }

private:
    struct Node {
        int val;
        Node* right;
        Node* down;
        Node() : val(-1), right(nullptr), down(nullptr) {}
        Node(int val) : val(val), right(nullptr), down(nullptr) {}
        Node(int val, Node* right, Node* down) : val(val), right(right), down(down) {}
    };
    
    Node* head;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */