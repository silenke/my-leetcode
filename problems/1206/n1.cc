#include "..\..\leetcode.h"

class Skiplist {
public:
    Skiplist() : root(new Node) {

    }
    
    bool search(int target) {

        Node* curr = root;
        while (curr) {
            while (curr->right && target > curr->right->val) {
                curr = curr->right;
            }
            if (curr->right && target == curr->right->val) {
                return true;
            }
            curr = curr->down;
        }
        return false;
    }
    
    void add(int num) {

        stack<Node*> s;
        Node* curr = root;
        while (curr) {
            while (curr->right && num > curr->right->val) {
                curr = curr->right;
            }
            s.emplace(curr);
            curr = curr->down;
        }
        
        bool insert = true;
        Node* down = nullptr;
        while (!s.empty() && insert) {
            curr = s.top(); s.pop();
            curr->right = new Node(num, curr->right, down);
            down = curr->right;
            insert = rand() & 1;
        }

        if (insert) {
            root = new Node(-1, new Node(num, nullptr, down), root);
        }
    }
    
    bool erase(int num) {

        bool found = false;
        Node* curr = root;
        while (curr) {
            while (curr->right && num > curr->right->val) {
                curr = curr->right;
            }
            if (curr->right && num == curr->right->val) {
                found = true;
                Node* node = curr->right;
                curr->right = node->right;
                delete node;
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

    Node* root;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */