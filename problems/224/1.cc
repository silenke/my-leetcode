class Solution {
public:
    int calculate(string s) {

        int i = 0;
        return calculate(s, i);
    }

private:
    int calculate(const string& s, int& i) {

        int res = 0;
        int num = 0;
        char sign = '+';
        while (i < s.size() && s[i] != ')') {
            char c = s[i++];
            if (c == '(') {
                num = calculate(s, i);
            }
            else if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i == s.size() || s[i] == ')') {
                if (sign == '+') res += num;
                else if (sign == '-') res -= num;
                num = 0;
                sign = c;
            }
        }
        i++;
        return res;
    }
};