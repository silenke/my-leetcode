#include "..\..\leetcode.h"

class NumArray {
public:
    NumArray(vector<int>& nums) : root(buildTree(nums, 0, nums.size() - 1)) {

    }
    
    void update(int index, int val) {

        update(root, index, val);
    }
    
    int sumRange(int left, int right) {

        return sumRange(root, left, right);
    }

private:
    struct Node {
        int start, end, sum;
        Node* left, * right;
        Node(int start, int end, int sum, Node* left = nullptr, Node* right = nullptr) :
            start(start), end(end), sum(sum), left(left), right(right) {}
    };

    Node* root;

    Node* buildTree(const vector<int>& nums, int start, int end) {

        if (start == end) return new Node(start, end, nums[start]);
        int mid = start + (end - start) / 2;
        Node* left = buildTree(nums, start, mid);
        Node* right = buildTree(nums, mid + 1, end);
        return new Node(start, end, left->sum + right->sum, left, right);
    }

    void update(Node* root, int i, int val) {

        if (root->start == root->end) {
            root->sum = val;
            return;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if (i <= mid) update(root->left, i, val);
        else update(root->right, i, val);
        root->sum = root->left->sum + root->right->sum;
    }

    int sumRange(Node* root, int start, int end) {

        if (root->start == start && root->end == end) return root->sum;
        int mid = root->start + (root->end - root->start) / 2;
        if (end <= mid) return sumRange(root->left, start, end);
        else if (start > mid) return sumRange(root->right, start, end);
        return sumRange(root->left, start, mid) + sumRange(root->right, mid + 1, end);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */