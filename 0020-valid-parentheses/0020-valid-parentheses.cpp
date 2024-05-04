class Solution {
public:
    bool isValid(string& s) {
        int n = s.size();

        if (n % 2) {
            return false;
        }

        stack<char> stk;

        for (char c:s) {
            if (c == '{' || c == '[' || c == '(') {
                stk.push(c);
            }

            else {
                if (stk.empty() || (c == ')' && stk.top() != '(') || (c == ']' && stk.top() != '[') || (c == '}' && stk.top() != '{')) {
                    return false;
                }
                stk.pop();
            }
        }

        return stk.empty();
    }
};