#include "..\..\leetcode.h"

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (const auto& n : nestedList) {
            dfs(n);
        }
    }
    
    int next() {
        return res[i++];
    }
    
    bool hasNext() {
        return i < res.size();
    }

private:
    int i = 0;
    vector<int> res;

    void dfs(const NestedInteger& n) {
        if (n.isInteger()) {
            res.emplace_back(n.getInteger());
            return;
        }
        const auto& l = n.getList();
        for (const auto& n : l) {
            dfs(n);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */