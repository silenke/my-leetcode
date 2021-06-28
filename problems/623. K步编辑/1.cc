#include "..\..\leetcode.h"

class Solution {
public:
    /**
     * @param words: a set of stirngs
     * @param target: a target string
     * @param k: An integer
     * @return: output all the strings that meet the requirements
     */
    vector<string> kDistance(vector<string> &words, string &target, int k) {
        // write your code here
        Node* root = new Node;
        for (const string& s : words) {
            insert(root, s);
        }
        vector<int> fp(target.size() + 1);
        for (int i = 0; i <= target.size(); i++) {
            fp[i] = i;
        }
        string s;
        vector<string> res;
        dfs(target, k, root, fp, s, res);
        return res;
    }

private:
    struct Node {
        Node* childs[26]{nullptr};
        bool isWord = false;
    };

    void insert(Node* curr, const string& word) {

        for (char c : word) {
            int i = c - 'a';
            if (curr->childs[i] == nullptr) {
                curr->childs[i] = new Node;
            }
            curr = curr->childs[i];
        }
        curr->isWord = true;
    }

    void dfs(const string& target, int k, Node* curr,
        const vector<int>& fp, string& s, vector<string>& res)
    {   // fp[j]：以父节点结尾的字符串和tatget前j个字符的最小编辑距离
        // fc[j]：以子节点结尾的字符串和tatget前j个字符的最小编辑距离
        if (curr->isWord && fp.back() <= k) {
            res.emplace_back(s);
        }
        vector<int> fc(target.size() + 1);
        for (int c = 'a'; c <= 'z'; c++) {
            if (curr->childs[c - 'a'] == nullptr) continue;
            fc[0] = fp[0] + 1;
            for (int i = 1; i <= target.size(); i++) {
                if (c == target[i - 1]) {
                    fc[i] = fp[i - 1];
                }
                else {
                    fc[i] = min({fc[i - 1], fp[i], fp[i - 1]}) + 1;
                }
            }
            s.push_back(c);
            dfs(target, k, curr->childs[c - 'a'], fc, s, res);
            s.pop_back();
        }
    }
};