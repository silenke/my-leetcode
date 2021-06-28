#include "..\..\leetcode.h"

class Solution {
public:
    int maxXOR(vector<int>& nums) {
        
        int res = INT_MIN;
        int x = 0;
        insert(0);
        for (int n : nums) {
            x ^= n;
            res = max(res, find(x));
            insert(x);
        }
        return res;
    }
    
private:
    struct Node {
        Node* childs[2]{nullptr};
    };
    
    Node* root = new Node;
    
    void insert(int num) {
        
        Node* curr = root;
        for (int i = 31; i >= 0; i--) {
            int j = (num >> i) & 1;
            if (curr->childs[j] == nullptr) {
                curr->childs[j] = new Node;
            }
            curr = curr->childs[j];
        }
    }
    
    int find(int num) {
        
        int res = 0;
        Node* curr = root;
        for (int i = 31; i >= 0; i--) {
            int j = (num >> i) & 1;
            int k = i == 31 ? j : j ^ 1;
            if (curr->childs[k] == nullptr) k ^= 1;
            res += (j ^ k) << i;
            curr = curr->childs[k];
        }
        return res;
    }
};