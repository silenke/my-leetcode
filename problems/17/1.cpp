#include <iostream>
#include <vector>

using namespace std;

// Time complexity: O(2^n)
// Space complexity: O(n)

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits == "")
            return {};

        string s;
        findCombination(digits, 0, s);
        return ans;
    }

private:
    vector<string> ans;

    vector<string> map = {
        " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void findCombination(const string &digits, int index, const string &s) {

        if (index == digits.size()) {
            ans.push_back(s);
            return;
        }

        string str = map[digits[index] - '0'];
        for (char &c : str) {
            findCombination(digits, index + 1, s + c);
        }
    }
};

int main() {

    string digits = "23";
    vector<string> ans = Solution().letterCombinations(digits);
    for (string &s : ans)
        cout << s << " ";

    return 0;
}